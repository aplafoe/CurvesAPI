cmake_minimum_required (VERSION 3.24)

project (Curves)

set (CMAKE_CXX_STANDARD 20)

set (LIB_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/CurvesAPI.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CurvesAPI.cpp
)

add_library(Curves SHARED ${LIB_SRC})

set_target_properties(Curves PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN 1
)
