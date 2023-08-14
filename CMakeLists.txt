cmake_minimum_required(VERSION 3.12)
project(umeteum CXX)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC userver-core)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

add_executable(${PROJECT_NAME}_unittest
    unittests/models/current_weather_test.cpp
    unittests/models/daypart_weather_test.cpp
)
target_link_libraries(${PROJECT_NAME}_unittest PRIVATE ${PROJECT_NAME} userver-utest)
add_google_tests(${PROJECT_NAME}_unittest)
