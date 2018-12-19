cmake_minimum_required(VERSION 2.8.3)

project("VisionTools")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

message("Build type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3 ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -std=c++11 -fopenmp")
if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG")
endif()

find_package(OpenCV 3.0 REQUIRED)

if(NOT OpenCV_FOUND)
    find_package(OpenCV 2.4.3 QUIET)
    if(NOT OpenCV_FOUND)
        message(FATAL_ERROR "OpenCV > 2.4.3 not found.")
    endif()
endif()

if(NOT OpenCV_VERSION VERSION_LESS "3.0")
  add_definitions(-DOPENCV_3)
endif()

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
)

link_directories(${CMAKE_BINARY_DIR}/bin)

add_executable(main.exe src/main.cpp)

target_link_libraries(main.exe ${OpenCV_LIBS})

