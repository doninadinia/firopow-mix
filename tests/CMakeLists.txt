add_executable(firopow-mix_tests test_core.cpp)
target_link_libraries(firopow-mix_tests PRIVATE work)
target_include_directories(firopow-mix_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME core COMMAND firopow-mix_tests)
