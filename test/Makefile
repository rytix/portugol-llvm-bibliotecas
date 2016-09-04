#CC especifica o compilador
CC = gcc

LINKER_FLAGS = -lmingw32 -lSDL2 -lSDL2main

BIN_FOLDER = bin
OBJ_FOLDER = obj
LIB_FOLDER = lib
SRC_FOLDER = src

OUTPUT_FILE = programa

all: make_dir build_bitcode build_object compile copy_libs

make_dir:
	mkdir -p $(OBJ_FOLDER)
	mkdir -p $(BIN_FOLDER)

build_bitcode:
	java -jar tools/portugol-compiler-llvm.jar $(SRC_FOLDER)/programa.por -o $(OBJ_FOLDER)/programa.bc

build_object:
	llc $(OBJ_FOLDER)/*.bc -filetype=obj -o $(OBJ_FOLDER)/$(OUTPUT_FILE).o

copy_libs:
	cp $(LIB_FOLDER)/*.dll $(BIN_FOLDER)/

compile:
	$(CC)  $(OBJ_FOLDER)/$(OUTPUT_FILE).o $(LIB_FOLDER)/*.o $(LINKER_FLAGS) -o $(BIN_FOLDER)/$(OUTPUT_FILE).exe

clean:
	rm -R $(OBJ_FOLDER)
	rm -R $(BIN_FOLDER)

run: all 
	reset
	bin\programa.exe