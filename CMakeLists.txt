cmake_minimum_required(VERSION 3.0.0)
project(project-c VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(include lib)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(project-c ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
