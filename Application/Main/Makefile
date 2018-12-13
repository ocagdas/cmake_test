
all:
	g++ -Wall -Wextra -Werror -g3 -I../LogPkg/include/ -I../ModemPkg/include/ -I../ThreadingPkg/include/ -Isrc/ --std=c++11 -c src/nix_pc/main.cpp
	g++ main.o -L../LogPkg/lib -L../ModemPkg/lib -L../ThreadingPkg/lib -llogpkg -lmodempkg -lthreadingpkg -lstdc++ -lpthread -o x86_64.bin

clean:
	rm -f *.o
	rm -f *.bin
