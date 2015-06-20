all: help
cpp_release:
	g++ task1.cpp util.c -o task1 -std=c++11
cpp_debug:
	g++ task1.cpp util.c -o task1 -g -std=c++11
wcpp_release:
	i586-mingw32msvc-g++ task1.cpp util.c -o task1.exe -std=c++11
wcpp_debug:
	i586-mingw32msvc-g++ task1.cpp util.c -o task1.exe -g -std=c++11
precompile:
	g++ util.h -std=c++11
debug:
	gdb ./task1
run:
	./task1
clear:
	rm ./task1
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
