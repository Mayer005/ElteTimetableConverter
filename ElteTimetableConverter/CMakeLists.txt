cmake_minimum_required(VERSION 3.10)
project(ElteTimeTableConverter)

set(CMAKE_CXX_STANDARD 17)

add_executable(serialize main.cpp Serialize.cpp Lesson.cpp)

if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")  # /MT kapcsoló beállítása
endif()