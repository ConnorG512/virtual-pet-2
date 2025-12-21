cmake_minimum_required(VERSION 3.28)
project(VirtualPet2 C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# External compiled dependencies
add_subdirectory(extern/glad)

set(EXECUTABLE_NAME virtualpet2)

set(SOURCE_FILES
  src/main.cpp
  src/engine/sdl-window.cpp
  src/engine/file-object.cpp
  src/engine/image.cpp
  src/engine/opengl/render.cpp
  src/engine/user-input.cpp
  src/gameplay/init-game.cpp
  src/gameplay/statistic.cpp
  src/gameplay/pet.cpp
  src/gameplay/tick-manager.cpp
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
find_package(SDL3_image REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE
  SDL3::SDL3
  SDL3_image
)

target_include_directories(${EXECUTABLE_NAME} PRIVATE 
  "${CMAKE_SOURCE_DIR}/include"
  "${CMAKE_SOURCE_DIR}/extern"
)

install(TARGETS ${EXECUTABLE_NAME} RUNTIME DESTINATION bin)

