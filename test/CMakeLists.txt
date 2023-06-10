add_executable(main test_main.cpp)
target_compile_features(main PRIVATE cxx_std_20)
target_link_libraries(main PRIVATE nt::nt)
add_test(test_main main)
