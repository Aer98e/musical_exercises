cmake_minimum_required(VERSION 3.20)
project(musicalExercises VERSION 3.0 LANGUAGES CXX)

add_library(generic INTERFACE)
target_include_directories(generic INTERFACE include)
target_compile_features(generic INTERFACE cxx_std_20)
target_compile_options(generic INTERFACE
    $<$<CONFIG:Release>:-O2>
    $<$<CONFIG:Release>:-flto>
    $<$<CONFIG:Debug>:-Wall>
    $<$<CONFIG:Debug>:-Wextra>
    $<$<CONFIG:Debug>:-Werror>
    $<$<CONFIG:Debug>:-g>
)

set(SOURCE_FILES
    src/api_flutter.cpp
    
    src/exercises_functions.cpp
    
    src/data_music.cpp
    src/music_utils.cpp
    
    src/note.cpp
    src/scale.cpp
    src/interval_network.cpp
)

add_library(music_core SHARED ${SOURCE_FILES})
target_link_libraries(music_core PRIVATE generic)

target_include_directories(music_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/nlohmann
)

set_target_properties(music_core PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
    INTERPROCEDURAL_OPTIMIZATION_RELEASE ON
)
