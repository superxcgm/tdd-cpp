cmake_minimum_required(VERSION 3.15)
project(tdd_cpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
aux_source_directory(src SRC_FILES)
aux_source_directory(. CWD_FILES)

add_library(tdd_cpp SHARED ${SRC_FILES})
add_executable(main ${CWD_FILES} ${SRC_FILES})

add_subdirectory(test)
