CC = gcc

LINKER_FLAGS = -lmingw32

BUILD_FOLDER = lib

LIBRARIES = -lSDL2 -lSDL2main -lSDL2_image

TEST_LIB_FOLDER = ../test/lib


#Windows
windows: make_windows compile_windows copy_to_test move_windows

make_windows:
	@echo Construindo pastas
	mkdir -p ../windows/$(BUILD_FOLDER)

compile_windows:
	@echo Compilando bibliotecas
	
	$(CC) -c *.c -g

move_windows:
	@echo Movendo para pasta bin
	mv *.o ../windows/$(BUILD_FOLDER)


copy_to_test:
	@echo Copiando para o projeto de teste
	cp *.o $(TEST_LIB_FOLDER)