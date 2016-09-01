project(PortugolLLVM)
cmake_minimum_required(VERSION 0.1.0)

set(CMAKE_C_COMPILER gcc -m64)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(Graficos graficos.c)
target_link_libraries(Graficos ${CONAN_LIBS})