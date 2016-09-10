#CC especifica o compilador
CC = gcc

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows

BIN_FOLDER = bin
OBJ_FOLDER = obj
LIB_FOLDER = libs
SRC_FOLDER = src

OUTPUT_FILE = programa

all: make_dir build_bitcode build_object compile copy_libs

make_dir:
	@echo Cria pastas
	mkdir -p $(OBJ_FOLDER)
	mkdir -p $(BIN_FOLDER)

build_bitcode:
	@echo Compila programa portugol - frontend
	java -jar ../src/tools/portugol-core-llvm.jar $(SRC_FOLDER)/programa.por -o $(OBJ_FOLDER)/programa.bc

build_object:
	@echo Compila programa portugol - backend
	llc $(OBJ_FOLDER)/*.bc -filetype=obj -o $(OBJ_FOLDER)/$(OUTPUT_FILE).o

copy_libs:
	@echo Copia arquivos
	cp $(LIB_FOLDER)/*.dll $(BIN_FOLDER)/


compile:
	@echo Linka arquivos
	$(CC) $(OBJ_FOLDER)/$(OUTPUT_FILE).o $(LIB_FOLDER)/*.o $(LINKER_FLAGS) -o $(BIN_FOLDER)/$(OUTPUT_FILE).exe

clean:
	@Limpa a bagunça
	rm -R $(OBJ_FOLDER)
	rm -R $(BIN_FOLDER)

run: all 
	reset
	bin\programa.exe