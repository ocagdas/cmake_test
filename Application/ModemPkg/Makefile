

all:
	g++ -Wall -Wextra -Werror -Iinclude/ModemPkg -I../LogPkg/include --std=c++11 -g3 -c src/IModemController.cpp src/ModemContImpl.cpp
	ar cr lib/libmodempkg.a IModemController.o ModemContImpl.o

clean:
	rm -f *.o
	rm -f lib/*.a
