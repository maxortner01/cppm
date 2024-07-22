cmake_minimum_required(VERSION 3.8)

project(cppm)

set(CPP_VERSION 17 CACHE STRING "C++ standard to use")
set(CMAKE_CXX_STANDARD ${CPP_VERSION})
message("Using standard C++${CPP_VERSION}")

add_executable(main src/Angle.cpp main.cpp)

if (CPP_VERSION EQUAL 20)
    include(CheckIncludeFileCXX)
    check_include_file_cxx(numbers CHECK_NUMBERS)
    if (CHECK_NUMBERS EQUAL 0)
        message(WARN "numbers.h not found")
    else()
        target_compile_definitions(main PRIVATE USE_NUMBERS)
    endif()
endif()

target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)