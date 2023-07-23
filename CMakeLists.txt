cmake_minimum_required(VERSION 3.23)

project(
    nt
    VERSION 0.2.0
    DESCRIPTION "Rust-like numeric types in C++"
    HOMEPAGE_URL "https://github.com/jimmy-park/nt"
    LANGUAGES CXX
)

include(cmake/CompileOptions.cmake)

option(NT_INSTALL "Install headers and CMake targets" OFF)

add_library(nt INTERFACE)
add_library(nt::nt ALIAS nt)
target_compile_features(nt INTERFACE cxx_std_14)
target_sources(nt INTERFACE
    FILE_SET HEADERS
    BASE_DIRS include
    FILES include/nt.hpp
)

if(NT_INSTALL)
    include(CMakePackageConfigHelpers)
    include(GNUInstallDirs)

    write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/nt-config-version.cmake
        COMPATIBILITY SameMajorVersion
    )
    install(
        TARGETS nt
        EXPORT ntTargets
        FILE_SET HEADERS
    )
    install(
        EXPORT ntTargets
        NAMESPACE nt::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/nt
    )
    install(
        FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/nt-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/nt-config-version.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/nt
    )
endif()

if(PROJECT_IS_TOP_LEVEL AND NOT CMAKE_CROSSCOMPILING)
    include(CTest)
    add_subdirectory(test)
endif()
