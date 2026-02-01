cmake_minimum_required(VERSION 3.15)
project(musicalExercises VERSION 2.0 LANGUAGES CXX)

add_library(generic INTERFACE)
target_include_directories(generic INTERFACE include)
target_compile_features(generic INTERFACE cxx_std_20)
target_compile_options(generic INTERFACE -Wall -Wextra -Werror)

add_library(musicalObjects STATIC
    src/note.cpp
    src/scale.cpp
    src/interval_network.cpp
    )
target_link_libraries(musicalObjects PUBLIC generic)

add_library(musicalData STATIC src/data_music.cpp)
target_link_libraries(musicalData PUBLIC generic)

add_library(musicalExercises STATIC src/exercises_functions.cpp)
target_link_libraries(musicalExercises PUBLIC musicalObjects)

add_library(util STATIC src/music_utils.cpp)
target_link_libraries(util PUBLIC generic)

add_executable(TeoricExercises src/main.cpp)
target_link_libraries(TeoricExercises PRIVATE musicalObjects musicalExercises util musicalData)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
