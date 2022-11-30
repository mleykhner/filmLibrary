cmake_minimum_required(VERSION 3.23)
project(filmLibrary)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
        *.h
        *.cpp
)
add_executable(filmLibrary ${SOURCE_FILES} ${SOURCES} TextButton.cpp TextButton.h)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(filmLibrary sfml-system sfml-window sfml-graphics sfml-audio sfml-network)