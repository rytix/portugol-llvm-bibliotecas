#OBJS specifies which files to compile as part of the project
OBJS = Graficos.c

#CC specifies which compiler we're using
CC = gcc

LINKER_FLAGS = -lmingw32

BUILD_FOLDER = build

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = Graficos.o


all: make program

make: 
	mkdir -p $(BUILD_FOLDER)

program: $(OBJS)
	$(CC) -c -o $(BUILD_FOLDER)/$(OBJ_NAME) $(OBJS) $(INCLUDE_PATHS) $(LINKER_FLAGS) $(LIBRARY_PATHS)

