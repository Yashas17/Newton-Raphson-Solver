PROJECT(Newton-Raphson)
CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(".")

CONFIGURE_FILE(example/data.json data.json)

ADD_EXECUTABLE(newton-raphson src/main.cpp src/equation.cpp src/functions.cpp src/readData.cpp)
ADD_EXECUTABLE(unittest test/unittest.cpp src/equation.cpp src/functions.cpp)