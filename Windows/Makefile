CC = gcc

LINKER_FLAGS = -lmingw32

BUILD_FOLDER = build

LIBRARIES = -lSDL2 -lSDL2main

all: make compile move

make: 
	mkdir -p $(BUILD_FOLDER)

compile:
	$(CC) -c *.c -g

move:
	mv *.o $(BUILD_FOLDER)