NDK_PATH = C:\Users\Bernardo\Downloads\android-ndk-r12b-windows-x86_64\android-ndk-r12b

FILE_SOURCE = Graficos.c ES.c Util.c

FILE_OBJ = Graficos.o ES.o Util.o

CC_ANDROID = /toolchains/llvm/prebuilt/windows-x86_64/bin/clang.exe

CC = gcc

TOOLCHAINS = /toolchains/arm-linux-androideabi-4.9/prebuilt/windows-x86_64

LINKER_FLAGS = -lmingw32

BUILD_FOLDER = libs

OBJ_FOLDER = obj

LIBRARIES = -lSDL2 -lSDL2main -lSDL2_image

TEST_LIB_FOLDER = ../test/libs


#Android
android: make_android build_sdl_android compile_android compile_android_so move_android copy_to_test_android

make_android:
	@echo ******************* Construindo pastas *******************
	mkdir -p ../android/$(BUILD_FOLDER)/armeabi-v7a
	mkdir -p ../android/$(OBJ_FOLDER)

build_sdl_android:
	@echo ******************* Compilando SDL... isso pode demorar alguns minutos. *******************
	ndk-build NDK_PROJECT_PATH=../android/

compile_android:
	@echo ******************* Compilando bibliotecas *******************
	$(NDK_PATH)$(CC_ANDROID) -MMD -MP -gcc-toolchain $(NDK_PATH)$(TOOLCHAINS) -fpic -ffunction-sections -funwind-tables -fstack-protector-strong -Wno-invalid-command-line-argument -Wno-unused-command-line-argument -no-canonical-prefixes -fno-integrated-as -g -target armv7-none-linux-androideabi -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16 -mthumb -Os -DNDEBUG  -I../android/jni/SDL2_image -I../android/jni/SDL/include -DANDROID  -Wa,--noexecstack -Wformat -Werror=format-security    -isystem $(NDK_PATH)/platforms/android-23/arch-arm/usr/include -c  $(FILE_SOURCE)

compile_android_so:
	$(NDK_PATH)$(CC_ANDROID) -Wl,-soname,libportugol.so -shared --sysroot=$(NDK_PATH)/platforms/android-23/arch-arm $(FILE_OBJ) -lgcc ../android/libs/armeabi-v7a/libSDL2.so ../android/libs/armeabi-v7a/libSDL2_image.so -gcc-toolchain $(NDK_PATH)/toolchains/arm-linux-androideabi-4.9/prebuilt/windows-x86_64 -no-canonical-prefixes -target armv7-none-linux-androideabi -Wl,--fix-cortex-a8  -Wl,--build-id -Wl,--no-undefined -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now -Wl,--warn-shared-textrel -Wl,--fatal-warnings   -L$(NDK_PATH)/platforms/android-23/arch-arm/usr/lib -lGLESv1_CM -lGLESv2 -llog -lc -lm -o ../android/libs/armeabi-v7a/libportugol.so

move_android:
	@echo ******************* Movendo para pasta obj *******************
	mv *.o ../android/$(OBJ_FOLDER)
	mv *.d ../android/$(OBJ_FOLDER)
	mkdir -p ../test/android-project/$(BUILD_FOLDER)/
	cp -avr ../android/$(BUILD_FOLDER)/* ../test/android-project/$(BUILD_FOLDER)/
copy_to_test_android:


#Windows
windows: make_windows compile_windows copy_to_test move_windows

make_windows:
	@echo Construindo pastas
	mkdir -p $(TEST_LIB_FOLDER)
	mkdir -p ../windows/$(BUILD_FOLDER)

compile_windows:
	@echo Compilando bibliotecas

	$(CC) -c *.c -g

move_windows:
	@echo Movendo para pasta bin
	mv *.o ../windows/$(BUILD_FOLDER)

#Utilitários
copy_to_test:
	@echo Copiando para o projeto de teste
	cp *.o $(TEST_LIB_FOLDER)