
all:
	g++ -Wall -Wextra -Werror -Iinclude/LogPkg  --std=c++11 -g3 -c src/ILogger.cpp src/LoggerImpl.cpp
	ar cr lib/liblogpkg.a ILogger.o LoggerImpl.o

clean:
	rm -f *.o
	rm -f lib/*.a
