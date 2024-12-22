cmake_minimum_required(VERSION 3.30)
project(ZombieArena)

set(CMAKE_CXX_STANDARD 23)
set(ROOT_DIR "${CMAKE_SOURCE_DIR}")

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

file(GLOB SOURCES "${ROOT_DIR}/src/*.cpp")

add_executable(ZombieArena ${SOURCES})

target_compile_definitions(ZombieArena PRIVATE ROOT_DIR="${ROOT_DIR}")
target_include_directories(ZombieArena PRIVATE "${ROOT_DIR}/include")
target_link_libraries(ZombieArena PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)