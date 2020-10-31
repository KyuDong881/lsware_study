cmake_minimum_required(VERSION 3.1)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(solution)

set(SOURCES
	solution.cc)

add_executable(solution ${SOURCES})

target_compile_options(solution PRIVATE -O2 -Wall)
target_compile_definitions(solution PRIVATE ONLINE_JUDGE BOJ)

target_link_options(solution PRIVATE -static)
target_link_libraries(solution PRIVATE m)

set_target_properties(solution PROPERTIES CXX_STANDARD 17)

