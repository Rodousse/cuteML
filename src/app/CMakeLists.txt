
add_executable(${PROJECT_NAME} ${APP_SOURCES} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE cute_engine)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DTEST_FILE="${CMAKE_CURRENT_SOURCE_DIR}/test.qml")
