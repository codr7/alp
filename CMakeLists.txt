cmake_minimum_required(VERSION 3.5)

project(alp)

set(CMAKE_CXX_COMPILER clang++)

add_compile_options(-std=c++17 -stdlib=libc++ -Wall -Werror -g)

file(GLOB_RECURSE src src/alp/*.cpp)
add_executable(alp ${src} src/main.cpp)
target_include_directories(alp PUBLIC src/)

install(FILES build/alp DESTINATION bin)
