OBJS = $(patsubst %.cpp,%.o,$(wildcard ./*.cpp))
CC = g++
DEBUG = -g3
CXXFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)


a.out : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o a.out

.PHONY : clean

clean:
	rm a.out $(OBJS)
