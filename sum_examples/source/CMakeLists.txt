
add_executable(CompensatedSum CompensatedSummation.cpp)
target_include_directories(CompensatedSum PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(CompensatedSum PRIVATE -mavx)  # remove -mavx if your cpu doesn't support it