cmake_minimum_required(VERSION 3.19.0)

project(main)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(SRC ${PROJECT_SOURCE_DIR}/src)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(
    ${PROJECT_NAME} 
    ${SRC}/main.cpp
    ${SRC}/page.cpp
    ${SRC}/file_loader.cpp
    ${SRC}/keyboard_input_observer.cpp
    )

find_package(SFML COMPONENTS graphics window system)

set(SFML_STATIC_LIBRARIES TRUE)


file(COPY font DESTINATION ${PROJECT_BINARY_DIR})

install(TARGETS ${PROJECT_NAME})

add_subdirectory(lib)

target_link_libraries(${PROJECT_NAME} ui sfml-graphics sfml-audio sfml-window)
