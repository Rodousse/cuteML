
set(CUTEML_SOURCES
     cuteml/Expression.cpp
     cuteml/Expression.hpp
     cuteml/ExpressionNode.cpp
     cuteml/ExpressionNode.hpp
     cuteml/fileIO.cpp
     cuteml/fileIO.hpp
     cuteml/File.cpp
     cuteml/File.hpp
     cuteml/FormatParameters.hpp
     cuteml/scaner.hpp
     cuteml/scaner.cpp
     )

add_library(cute_engine ${CUTEML_SOURCES})

target_compile_features(cute_engine PUBLIC cxx_std_17)
target_include_directories(cute_engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(cute_engine PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wunused -Woverloaded-virtual>
     $<$<CXX_COMPILER_ID:GNU>:
          -Wduplicated-cond -Wduplicated-branches -Wnull-dereference -Wuseless-cast>
     $<$<CXX_COMPILER_ID:MSVC>:
          /W4 /w14265 /w14640 /w14826 /w14928>)
