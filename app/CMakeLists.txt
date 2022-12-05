set (APP_SOURCES "main.cpp")

add_executable(${PROJECT_NAME} ${APP_SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${PROJECT_NAME}_lib)

if (${ENABLE_WARNINGS})
    target_set_warnings(TARGET ${PROJECT_NAME} ENABLE ON AS_ERROR OFF)
endif()

add_target_static_analyers(${PROJECT_NAME})
