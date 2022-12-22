cmake_minimum_required(VERSION 3.20)

project(sort LANGUAGES CXX)

file(GLOB src CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_executable(main)

target_include_directories(main PUBLIC include)
target_sources(main PUBLIC ${src})