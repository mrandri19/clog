add_executable(clog main.cc)
target_include_directories(clog PUBLIC ../lib)
target_link_libraries(clog PUBLIC clog_lib)
