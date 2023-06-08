cmake_minimum_required(VERSION 3.23)

project(
    number
    VERSION 0.2.0
    DESCRIPTION "Rust-like numeric types in C++"
    HOMEPAGE_URL "https://github.com/jimmy-park/number"
    LANGUAGES CXX
)

include(cmake/CompileOptions.cmake)

add_library(number INTERFACE)
add_library(number::number ALIAS number)
target_compile_features(number INTERFACE cxx_std_14)
target_sources(number INTERFACE
    FILE_SET HEADERS
    BASE_DIRS include
    FILES include/number.hpp
)

if(PROJECT_IS_TOP_LEVEL AND NOT CMAKE_CROSSCOMPILING)
    include(CTest)
    add_subdirectory(test)
endif()
