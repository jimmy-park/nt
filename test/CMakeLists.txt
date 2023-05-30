add_executable(main test_main.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE number::number)
add_test(test_main main)
