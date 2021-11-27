project(Newton-Raphson)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)
set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

cmake_minimum_required(VERSION 2.6)

INCLUDE_DIRECTORIES(".")

ADD_EXECUTABLE(newton-raphson 	main.cpp functions.h)
