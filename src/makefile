CC = gcc
CFLAGS = -I

DEPS = Room.h tests.h production.h LinkedList.h structures.h 
OBJ = HW3StarterGetAClue.o Room.o LinkedList.o production.o tests.o structures.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

HW3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm *.o
	rm HW3
