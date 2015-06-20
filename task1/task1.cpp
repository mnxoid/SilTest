/** 
 * @file	task1.cpp
 * @brief	C++ source of the app that detects two frequencies in a data stream
 *
 * 
 * Copyright 2015 by mnxoid,
 * 
 * This software is the confidential and proprietary information
 * of mnxoid ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with mnxoid.
 **/
//------------------Includes------------------------------------
//#include "util.h"//Unused, just for CleanInput()
#include <iostream>
#include <fstream>
#include <string>
//------------------Namespaces----------------------------------
using namespace std;
//------------------Utilty function definitions-----------------
/**
 * A function that converts wavelength (us) into frequency string(Hz)
 * @param  	   int len - wave length
 * @return     string - frequency string
 */
string freq(int len);
//------------------Main function-------------------------------
int main()
{
	ifstream inFile("input.txt");
	bool beg[2]={false,false};//Flags that show if we are in a wave
	bool found[2]={false,false};//Flags that show if we already found the wave lengths
	int len[2]={0,0};//Lengths of the waves
	int curr,prev;//current and previous input
	inFile >> prev;//initial input
	while(!inFile.eof() && !(found[0]&&found[1]))//while lengths aren't found and input is available
	{
		inFile >> curr;//input next number
		if(!found[0])//we still have to find the first length
		{
			if((curr & 1) != (prev & 1))//the signal has changed
			{
				if(beg[0])found[0]=true;//it changed back, we're at the end
				else
				{
					beg[0]=true;//we're at the start
					len[0]++;//length increment
				}
			} else if (beg[0]) {//we're in the middle of a wave
				len[0]++;//length increment
			}
		}
		if(!found[1])//we still have to find the second length
		{
			if((curr & 2) != (prev & 2))//the signal has changed
			{
				if(beg[1])found[1]=true;//it changed back, we're at the end
				else
				{
					beg[1]=true;//we're at the start
					len[1]++;//length increment
				}
			} else if (beg[1]) {//we're in the middle of a wave
				len[1]++;//length increment
			}
		}
		prev=curr;//save input for comparsion
	}
	if(found[0]&&found[1])
	{
		cout << "First frequency :" << freq(len[0]) << endl;
		cout << "Second frequency :" << freq(len[1]) << endl;
	} else {
		cout << "Error, not enough information" << endl;
	}
	//CleanInput();//wait for <ENTER>
	return 0;
}
//------------------Utility functions---------------------------
string freq(int len)
{
	string res = "";
	double fr=1000/((double)len*2);
	res += to_string(fr);
	res += "KHz";
	return res;
}