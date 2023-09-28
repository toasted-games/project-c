cmake_minimum_required(VERSION 3.0.0)
project(project-c VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

# Declare tests
include(CTest)
enable_testing()

# Add raylib
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git 
    GIT_TAG master
)
FetchContent_MakeAvailable(raylib)

# Add source files
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/src/*.hpp")
set(INCLUDES "${CMAKE_CURRENT_LIST_DIR}/include/")

# Declare executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

add_custom_target(copy_assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets/ ${CMAKE_CURRENT_BINARY_DIR}/Debug/assets/ DEPENDS ${CMAKE_CURRENT_LIST_DIR}/assets/)
add_dependencies(${PROJECT_NAME} copy_assets)

add_definitions(-w)

# Add assets
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/assets/")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)