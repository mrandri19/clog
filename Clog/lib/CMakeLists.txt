add_library(clog_lib STATIC clog.cc clog.h)
target_compile_features(clog_lib PUBLIC cxx_std_17)
target_link_libraries(clog_lib PUBLIC)
