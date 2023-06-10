cmake_minimum_required(VERSION 3.23)

project(
    nt
    VERSION 0.2.0
    DESCRIPTION "Rust-like numeric types in C++"
    HOMEPAGE_URL "https://github.com/jimmy-park/nt"
    LANGUAGES CXX
)

include(cmake/CompileOptions.cmake)

add_library(nt INTERFACE)
add_library(nt::nt ALIAS nt)
target_compile_features(nt INTERFACE cxx_std_14)
target_sources(nt INTERFACE
    FILE_SET HEADERS
    BASE_DIRS include
    FILES include/nt.hpp
)

if(PROJECT_IS_TOP_LEVEL AND NOT CMAKE_CROSSCOMPILING)
    include(CTest)
    add_subdirectory(test)
endif()
