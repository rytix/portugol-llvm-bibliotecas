CC = gcc

LINKER_FLAGS = -lmingw32

BUILD_FOLDER = build

LIBRARIES = -lSDL2 -lSDL2main

TEST_LIB_FOLDER = ../test/lib

all: make compile copy_to_test move

make: 
	mkdir -p $(BUILD_FOLDER)

compile:
	$(CC) -c *.c -g

copy_to_test:
	cp *.o $(TEST_LIB_FOLDER)

move:
	mv *.o $(BUILD_FOLDER)