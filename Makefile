CC = g++
CFLAGS = -Wall -g -std=c++0x
LFLAGS = -L ~/local/lib
INCLUDES = -I ~/local/include

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)
TEST_SRCS := $(wildcard test/*.cpp)
TEST_OBJS := $(TEST_SRCS:.cpp=.o)


install: $(OBJS)
	cp src/*.hpp ~/local/include/momo
	ar rvs ~/local/lib/libGslFace.a src/*.o

src/%.o: src/%.cpp
	$(CC) -c $(INCLUDES) $(CFLAGS) $<
	mv *.o src

