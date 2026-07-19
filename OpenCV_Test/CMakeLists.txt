cmake_minimum_required(VERSION 3.10)
project(LetterboxOpencv)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(fmt REQUIRED)

include_directories(
        ${PROJECT_SOURCE_DIR}/Inc
)

add_executable(main ./Src/main.cpp ./Tool/image_utils.cpp)
target_link_libraries(main ${OpenCV_LIBS} fmt::fmt)