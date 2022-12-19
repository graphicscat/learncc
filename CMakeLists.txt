cmake_minimum_required(VERSION 3.10)

project(mycc LANGUAGES CXX)

add_executable(mycc)

file(GLOB src CONFIGURE_DEPENDS *.cpp)

target_sources(mycc PUBLIC ${src})