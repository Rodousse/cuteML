cmake_minimum_required(VERSION 3.12)

project(cuteml LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/main.cpp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_compile_options(${PROJECT_NAME} PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wunused -Woverloaded-virtual>
     $<$<CXX_COMPILER_ID:GNU>:
          -Wduplicated-cond -Wduplicated-branches -Wnull-dereference -Wuseless-cast>
     $<$<CXX_COMPILER_ID:MSVC>:
          /W4 /w14265 /w14640 /w14826 /w14928>)

