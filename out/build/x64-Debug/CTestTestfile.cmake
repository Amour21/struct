# CMake generated Testfile for 
# Source directory: C:/Users/Dmitriy Katyshev/struct
# Build directory: C:/Users/Dmitriy Katyshev/struct/out/build/x64-Debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(all_tests "C:/Users/Dmitriy Katyshev/struct/out/build/x64-Debug/all_tests.exe" "--gtest_color=yes")
set_tests_properties(all_tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Dmitriy Katyshev/struct/CMakeLists.txt;31;add_test;C:/Users/Dmitriy Katyshev/struct/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
