
add_executable(CompensatedSum CompensatedSummation.cpp)
target_include_directories(CompensatedSum PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(VectorAddition VectorAddition.cpp)