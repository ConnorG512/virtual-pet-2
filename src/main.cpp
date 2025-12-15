#include "sdl-window.hpp"
#include "glad/glad.h"
#include "primitive-shapes.hpp"
#include "file-object.hpp"
#include "glad/glad.h"

#include <cstdint>
#include <print>

auto main() -> int 
{
  Engine::SDL::Window current_window{};
  
  std::uint32_t VAO{};
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  std::uint32_t background_vbo;
  glGenBuffers(1, &background_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, background_vbo);
  glBufferData(GL_ARRAY_BUFFER, Utils::BasicShapes::FULL_SCREEN_RECTANGLE.size() * sizeof(float), Utils::BasicShapes::FULL_SCREEN_RECTANGLE.data(), GL_STATIC_DRAW);

  std::uint32_t background_vertex_shader{glCreateShader(GL_VERTEX_SHADER)};
  Engine::Utils::File background_vertex_file("src/shaders/default.vert");
  const GLchar* background_vertex_source = reinterpret_cast<const GLchar*>(background_vertex_file.GetFileData().data());
  glShaderSource(
      background_vertex_shader, 
      1, 
      &background_vertex_source, 
      reinterpret_cast<const GLint*>(&background_vertex_file.size())
  );
  glCompileShader(background_vertex_shader);

  std::uint32_t background_fragment_shader{glCreateShader(GL_FRAGMENT_SHADER)};
  Engine::Utils::File background_fragment_file("src/shaders/default.frag");
  const GLchar* background_fragment_source = reinterpret_cast<const GLchar*>(
      background_fragment_file.GetFileData().data()
  );
  glShaderSource(background_fragment_shader, 1, &background_fragment_source, nullptr);
  glCompileShader(background_fragment_shader);

  std::uint32_t shader_program{glCreateProgram()};
  glAttachShader(shader_program, background_vertex_shader);
  glAttachShader(shader_program, background_fragment_shader);
  glLinkProgram(shader_program);
  glUseProgram(shader_program);

  glDeleteShader(background_vertex_shader);
  glDeleteShader(background_fragment_shader);

  glVertexAttribPointer(
      0, 
      3, 
      GL_FLOAT, 
      GL_FALSE, 
      3 * sizeof(float), 
      (void*)0
  );
  glEnableVertexAttribArray(0);  
  

  bool is_running {true};
  while(is_running)
  {
    SDL_Event event{};
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_EVENT_QUIT)
        is_running = false;
      else if (event.type == SDL_EVENT_KEY_DOWN)
        current_window.resetDimentions();
    }

    // Main Loop.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shader_program);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    SDL_GL_SwapWindow(current_window.ptr());

  }

  SDL_Quit();

  return 0;
};
