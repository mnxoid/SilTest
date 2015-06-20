all: help
cpp_release:
	g++ task3.cpp util.c -o task3 -std=c++11
cpp_debug:
	g++ task3.cpp util.c -o task3 -g -std=c++11
wcpp_release:
	i586-mingw32msvc-g++ task3.cpp util.c -o task3.exe -std=c++11
wcpp_debug:
	i586-mingw32msvc-g++ task3.cpp util.c -o task3.exe -g -std=c++11
precompile:
	g++ util.h -std=c++11
debug:
	gdb ./task3
run:
	./task3
clear:
	rm ./task3
	rm ./util.h.gch
commit:
	git commit -a
	git push origin master
help:
	@echo "Options:"
	@echo "	cpp_release"
	@echo "	cpp_debug"
	@echo "	wcpp_release"
	@echo "	wcpp_debug"
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"
