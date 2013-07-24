OBJS = main.o AdjList.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

AdjList : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o AdjList

main.o : AdjList.h
	$(CC) $(CFLAGS) main.cpp

AdjList.o : AdjList.h AdjList.cpp Vertex.h Queue.h
	$(CC) $(CFLAGS) AdjList.cpp

clean:
	\rm *.o *~ AdjList

tar:
	tar cfv AdjList.tar main.cpp AdjList.h AdjList.cpp Queue.h Vertex.h \
makefile
