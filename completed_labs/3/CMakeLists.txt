cmake_minimum_required(VERSION 3.26)

project(
lab #Name of Project
VERSION 1.0.0 #Current Version
LANGUAGES C CXX #Languages used
)

set(CMAKE_CXX_STANDARD 20) # C++ Version Being Compiled
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES
        "src/*.h"
        "src/*.cpp"
)
add_executable(lab ${SOURCES} )
target_compile_options(lab PRIVATE -O0 -Wall)
