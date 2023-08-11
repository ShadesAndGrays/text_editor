cmake_minimum_required(VERSION 3.10.0)

project(main)

set(DLL_DIRECTORY ${PROJECT_SOURCE_DIR}/SFML/bin)
set(LIB_DIRECTORY ${PROJECT_SOURCE_DIR}/SFML/lib)

file(GLOB DLL_FILES ${DLL_DIRECTORY}/*.dll)
file(GLOB LIB_FILES ${LIB_DIRECTORY}/*.a)


include_directories(
    include
    SFML/include
)    


#set(SFML_STATIC_LIBRARIES TRUE)

set(SRC ${PROJECT_SOURCE_DIR}/src)

file(GLOB SOURCES ${SRC}/*.cpp)
message("sources files" ${SOURCES})
add_executable(${PROJECT_NAME} ${SOURCES})


foreach(DLL ${DLL_FILES})
  #  message("File:" ${DLL})
    target_link_libraries(${PROJECT_NAME} "${DLL}")
    file(COPY ${DLL} DESTINATION ${CMAKE_BINARY_DIR})
endforeach()


#foreach(LIB ${LIB_FILES})
#    message("File:" ${LIB})
 #   target_link_libraries(${PROJECT_NAME} "${LIB}")
#endforeach()
