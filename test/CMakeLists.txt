cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(Threads REQUIRED)

aux_source_directory(. TEST_FILES)
add_executable(tests ${TEST_FILES})

set(GMOCK_LIBS /usr/local/lib/libgmock.a /usr/local/lib/libgmock_main.a)

target_link_libraries(tests tdd_cpp ${GTEST_BOTH_LIBRARIES} ${GMOCK_LIBS} ${CMAKE_THREAD_LIBS_INIT})
gtest_discover_tests(tests)