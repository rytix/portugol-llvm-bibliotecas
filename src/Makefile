CC = gcc

LINKER_FLAGS = -lmingw32

BUILD_FOLDER = ../windows/lib

LIBRARIES = -lSDL2 -lSDL2main -lSDL2_image

TEST_LIB_FOLDER = ../test/lib

windows: make compile copy_to_test move

make: 
	mkdir -p $(BUILD_FOLDER)
	cd ../src

compile:
	$(CC) -c *.c -g

copy_to_test:
	cp *.o $(TEST_LIB_FOLDER)

move:
	mv *.o $(BUILD_FOLDER)