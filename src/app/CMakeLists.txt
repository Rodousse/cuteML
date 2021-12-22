
add_executable(${PROJECT_NAME} ${APP_SOURCES} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE cute_engine)
