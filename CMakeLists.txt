cmake_minimum_required(VERSION 3.28)
project(VirtualPet2 C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# External compiled dependencies
add_subdirectory(extern/glad)

set(EXECUTABLE_NAME virtualpet2)

set(SOURCE_FILES
  src/main.cpp
  src/sdl-window.cpp
  src/file-io.cpp
)

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

target_link_libraries(${EXECUTABLE_NAME} PRIVATE 
  glad
)

target_compile_options(${EXECUTABLE_NAME} PRIVATE
  -Wall
  -Wextra
  -Wpedantic
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug" AND UNIX AND NOT APPLE)
  target_compile_options(${EXECUTABLE_NAME} PRIVATE 
    -fsanitize=address,undefined
    -ggdb
  )
  target_link_options(${EXECUTABLE_NAME} PRIVATE 
    -fsanitize=address,undefined
  )
endif()

find_package(SDL3 REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE
  SDL3::SDL3
)

target_include_directories(${EXECUTABLE_NAME} PRIVATE 
  "${CMAKE_SOURCE_DIR}/include"
  "${CMAKE_SOURCE_DIR}/extern"
)

install(TARGETS ${EXECUTABLE_NAME} RUNTIME DESTINATION bin)

