cmake_minimum_required(VERSION 3.10)
project(Test)

include_directories(
        ${PROJECT_SOURCE_DIR}/Inc
)
# add_executable(result ./Src/test.cpp ./Tool/tool.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(opencv_test_app ./Src/test.cpp ./Tool/tool.cpp)
target_link_libraries(opencv_test_app ${OpenCV_LIBS})

find_package(fmt REQUIRED)
target_link_libraries(opencv_test_app fmt::fmt)