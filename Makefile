CC_FLAGS = -g -Wall

all: assign3

assign3: assign3.c assign3.h
	gcc ${CC_FLAGS} assign3.c -o assign3

clean:
	rm -rf *.o assign3