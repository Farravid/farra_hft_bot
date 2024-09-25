cmake_minimum_required(VERSION 3.14...3.22)

project(Benchmark LANGUAGES CXX)

# ---- Options ----

option(BENCHMARK_DOWNLOAD_DEPENDENCIES "Enable benchmark download dependencies" ON)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage("gh:google/benchmark@1.9.0")
CPMAddPackage(NAME Greeter SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

# ---- Create binary ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
add_executable(${PROJECT_NAME} ${sources})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23)
target_link_libraries(${PROJECT_NAME} Greeter::Greeter benchmark)
