cmake_minimum_required(VERSION 3.22)
project(MemLoader-cpp)

set(CMAKE_CXX_STANDARD 14)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

add_executable (MemLoader-cpp main.cpp)
target_link_libraries(MemLoader-cpp ${CURL_LIBRARIES} ${OpenCV_LIBS})
