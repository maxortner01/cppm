cmake_minimum_required(VERSION 3.10)

project(cppm)

set(CPP_VERSION 20 CACHE STRING "C++ standard to use")
set(CMAKE_CXX_STANDARD ${CPP_VERSION})
message("Using standard C++${CPP_VERSION}")

add_library(cppm src/Angle.cpp)

if (CPP_VERSION EQUAL 20)
    include(CheckIncludeFileCXX)
    check_include_file_cxx(numbers CHECK_NUMBERS)
    if (CHECK_NUMBERS EQUAL 0)
        message(WARN "numbers.h not found")
    else()
        target_compile_definitions(cppm PUBLIC USE_NUMBERS)
    endif()
endif()

target_include_directories(cppm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)