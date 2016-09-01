project(PortugolLLVM)
cmake_minimum_required(VERSION 0.1.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Graficos graficos.c)
target_link_libraries(Graficos ${CONAN_LIBS})