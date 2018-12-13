
all:
	g++ -Wall -Wextra -Werror -Iinclude/ThreadingPkg  --std=c++11 -g3 -c src/Threading.cpp
	ar cr lib/libthreadingpkg.a Threading.o
	#ld -r -o lib/libthreadingpkg_by_ld.o Threading.o

clean:
	rm -f *.o
	rm -f lib/*.a
