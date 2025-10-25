cmake_minimum_required(VERSION 3.20)

project(opengl-physics LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)
find_package(cglm REQUIRED)
find_package(glad REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.c")
file(GLOB_RECURSE HEADERS "include/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE 
    "${PROJECT_SOURCE_DIR}/include",
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    glfw
    cglm::cglm
    glad::glad
)

if(EXISTS "${CMAKE_SOURCE_DIR}/assets")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"
        COMMENT "Copying assets..."
    )
endif()