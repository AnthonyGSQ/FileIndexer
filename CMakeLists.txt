cmake_minimum_required(VERSION 3.10)

project(FileIndexerProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDAR 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(FileIndexer ${SOURCES})