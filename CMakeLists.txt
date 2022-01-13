project(Newton-Raphson)

cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(".")

ADD_EXECUTABLE(newton-raphson main.cpp equation.cpp functions.cpp readData.cpp)
