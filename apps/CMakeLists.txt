add_executable(app app.cpp)
target_compile_features(app PRIVATE cxx_std_17)

target_link_libraries(app PRIVATE PSyNet fmt::fmt)
target_include_directories(app INTERFACE ${CMAKE_SOURCE_DIR}/src)