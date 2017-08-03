cmake_minimum_required( VERSION 2.8 )

project( Lslam )

set(OpenCV_DIR "/usr/local/opencv3.2.0/share/OpenCV")

find_package( OpenCV REQUIRED )

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_library(${PROJECT_NAME} SHARED
src/Frame.cc
src/Line.cc
src/System.cc
)
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
)

#build Examples

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples)
add_executable( testLineDetector ${PROJECT_SOURCE_DIR}/Examples/testLineDetector.cc )
target_link_libraries(testLineDetector ${PROJECT_NAME})