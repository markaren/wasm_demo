set(CMAKE_TOOLCHAIN_FILE "$ENV{EMSDK}/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake" CACHE STRING "")

cmake_minimum_required(VERSION 3.15)
project(wasm_demo)

set(CMAKE_CXX_STANDARD 17)

add_executable(wasm_demo main.cpp)
target_link_libraries(wasm_demo
        PUBLIC
        embind
        )
set_target_properties(wasm_demo
        PROPERTIES LINK_FLAGS "-s WASM=1"
        )

set_target_properties(wasm_demo PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public"
        )



