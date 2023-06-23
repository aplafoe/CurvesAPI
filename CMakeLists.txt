cmake_minimum_required(VERSION 3.8)

project(optional_task)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/include)

add_executable(optional_tasks "optional_tasks.cpp")

include_directories(${INCLUDE_DIR})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(DLL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/x64-debug)
else()
    set(DLL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/x64-release)
endif()

add_library(Curves SHARED IMPORTED)
set_property(TARGET Curves PROPERTY IMPORTED_LOCATION ${DLL_DIR}/Curves.dll)
set_property(TARGET Curves PROPERTY IMPORTED_IMPLIB ${DLL_DIR}/Curves.lib)

target_link_libraries(optional_tasks PRIVATE Curves)

add_custom_command(TARGET optional_tasks POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${DLL_DIR}/Curves.dll"
        $<TARGET_FILE_DIR:optional_tasks>
)