NDK_PATH = ..\r16b

TOOLCHAINS = \toolchains\arm-linux-androideabi-4.9\prebuilt\windows-x86_64

FILE_SOURCE = ..\src\main.c obj\programa.bc

FILE_OBJ = main.o programa.o SDL_android_main.o

CC_ANDROID = \toolchains\llvm\prebuilt\windows-x86_64\bin\clang.exe

CC = gcc

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows

BIN_FOLDER = bin
OBJ_FOLDER = obj
LIB_FOLDER = libs
SRC_FOLDER = src

OUTPUT_FILE = programa


make_dir:
	@echo Cria pastas
	mkdir "$(OBJ_FOLDER)"
	mkdir "$(BIN_FOLDER)"

move_recursos_android:
	copy "recursos\*.*" "android-project\assets"

build_object_android:
	@echo Constroi objetos lib no android
	$(NDK_PATH)$(CC_ANDROID) -MMD -MP -gcc-toolchain $(NDK_PATH)$(TOOLCHAINS) -fpic -ffunction-sections -funwind-tables -fstack-protector-strong -Wno-invalid-command-line-argument -Wno-unused-command-line-argument -no-canonical-prefixes -fno-integrated-as -g -target armv7-none-linux-androideabi -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16 -mthumb -Os -DNDEBUG  -I..\android\jni\SDL2_image -I..\android\jni\SDL\include -I$(NDK_PATH)\sysroot\usr\include -I$(NDK_PATH)\sysroot\usr\include\arm-linux-androideabi -DANDROID  -Wa,--noexecstack -Wformat -Werror=format-security    -isystem $(NDK_PATH)\platforms\android-23\arch-arm\usr\lib -c  $(FILE_SOURCE) 
	$(NDK_PATH)$(CC_ANDROID) -MMD -MP -gcc-toolchain $(NDK_PATH)$(TOOLCHAINS) -fpic -ffunction-sections -funwind-tables -fstack-protector-strong -Wno-invalid-command-line-argument -Wno-unused-command-line-argument -no-canonical-prefixes -fno-integrated-as -g -target armv7-none-linux-androideabi -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16 -mthumb -Os -DNDEBUG  -I..\android\jni\SDL2_image -I..\android\jni\SDL\include -I$(NDK_PATH)\sysroot\usr\include -I$(NDK_PATH)\sysroot\usr\include\arm-linux-androideabi -DANDROID  -Wa,--noexecstack -Wformat -Werror=format-security    -isystem $(NDK_PATH)\platforms\android-23\arch-arm\usr\lib -c  ..\android\jni\SDL\src\main\android\SDL_android_main.c
	@echo Construido objetos lib no android

move_android:
	@echo Movendo arquivos
	move "*.o" "$(OBJ_FOLDER)"
	move "*.d" "$(OBJ_FOLDER)"

compile_android_so:
	@echo Criando a biblioteca compartilhada
	$(NDK_PATH)$(CC_ANDROID) -Wl,-soname,libmain.so -shared --sysroot=$(NDK_PATH)\platforms\android-23\arch-arm $(FILE_OBJ) -lgcc ..\android\libs\armeabi-v7a\libSDL2.so ..\android\libs\armeabi-v7a\libSDL2_image.so ..\android\libs\armeabi-v7a\libportugol.so -gcc-toolchain $(NDK_PATH)\toolchains\arm-linux-androideabi-4.9\prebuilt\windows-x86_64 -no-canonical-prefixes -target armv7-none-linux-androideabi -Wl,--fix-cortex-a8  -Wl,--build-id -Wl,--no-undefined -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now -Wl,--warn-shared-textrel -Wl,--fatal-warnings   -L$(NDK_PATH)\platforms\android-23\arch-arm\usr\lib -lGLESv1_CM -lGLESv2 -llog -lc -lm -o android-project\libs\armeabi-v7a\libmain.so

ant_install:
	@echo Instalando a aplicacao
	cd android-project &&\
		ant debug install

android: make_dir move_recursos_android build_bitcode build_object_android compile_android_so move_android ant_install


#WINDOWS
windows: make_dir move_recursos_widows build_bitcode build_object compile copy_libs

move_recursos_widows:
	copy "recursos" "bin"

build_bitcode:
	@echo Compila programa portugol - frontend
	java -jar ..\src\tools\portugol-core-llvm.jar $(SRC_FOLDER)\programa.por -o $(OBJ_FOLDER)\programa.bc

build_object:
	@echo Compila programa portugol - backend
	llc $(OBJ_FOLDER)\*.bc -filetype=obj -o $(OBJ_FOLDER)\$(OUTPUT_FILE).o

copy_libs:
	@echo Copia arquivos
	copy "$(LIB_FOLDER)\*.dll" "$(BIN_FOLDER)\"


compile:
	@echo Linka arquivos
	$(CC) $(OBJ_FOLDER)\$(OUTPUT_FILE).o $(LIB_FOLDER)\*.o $(LINKER_FLAGS) -o $(BIN_FOLDER)\$(OUTPUT_FILE).exe

clean:
	@Limpa a bagunça
	rm -R $(OBJ_FOLDER)
	rm -R $(BIN_FOLDER)