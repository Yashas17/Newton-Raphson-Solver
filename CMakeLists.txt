PROJECT(Newton-Raphson)
CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(".")

CONFIGURE_FILE(example/data.json data.json)

SET(CMAKE_CXX_FLAGS "-O0")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
#SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
#SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")

ADD_EXECUTABLE(newton-raphson src/main.cpp src/equation.cpp src/functions.cpp src/readData.cpp)
ADD_EXECUTABLE(unittest test/unittest.cpp src/equation.cpp src/functions.cpp)