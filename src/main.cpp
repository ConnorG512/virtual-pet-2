#include "sdl-window.hpp"
#include "glad/glad.h"
#include "primitive-shapes.hpp"
#include "file-object.hpp"
#include "glad/glad.h"
#include "errorbox.hpp"

#include <cstdint>
#include <print>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_messagebox.h>

auto main() -> int 
{
  Engine::SDL::Window current_window{};
  glViewport(0, 0, current_window.getCurrentDimensions().first, current_window.getCurrentDimensions().second);

  // Genertating a texture
  SDL_Surface* texture_image {IMG_Load("assets/image/background/HomeScreen.png")};
  if (texture_image == nullptr)
  {
    Engine::ErrorBox::CreateErrorBox<Engine::ErrorBox::BoxType::error>(
        "Failed to load image texture!",
        current_window.ptr()
        );
    return -1;
  }
  std::println("Texture loaded: H{0}W{1}", texture_image->h, texture_image->w);

  // Converting the image colour format:
  SDL_Surface* converted_texture_image {SDL_ConvertSurface(texture_image, SDL_PIXELFORMAT_RGBA32)};
  
  GLuint texture_id {0};
  glGenTextures(1, &texture_id);
  glBindTexture(GL_TEXTURE_2D, texture_id);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  //glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexImage2D(
      GL_TEXTURE_2D, 
      0, 
      GL_RGBA, 
      converted_texture_image->w, 
      converted_texture_image->h, 
      0, 
      GL_RGBA, 
      GL_UNSIGNED_BYTE, 
      converted_texture_image->pixels
  );
  //glGenerateMipmap(GL_TEXTURE_2D);
  
  SDL_DestroySurface(texture_image);
  SDL_DestroySurface(converted_texture_image);

  //VAO
  std::uint32_t VAO{};
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
  
  // VBO
  std::uint32_t background_vbo;
  glGenBuffers(1, &background_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, background_vbo);
  glBufferData(GL_ARRAY_BUFFER, Utils::BasicShapes::FULL_SCREEN_RECTANGLE.size() * sizeof(float), Utils::BasicShapes::FULL_SCREEN_RECTANGLE.data(), GL_STATIC_DRAW);
  
  // Vertex
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
  
  // Fragment
  std::uint32_t background_fragment_shader{glCreateShader(GL_FRAGMENT_SHADER)};
  Engine::Utils::File background_fragment_file("src/shaders/default.frag");
  const GLchar* background_fragment_source = reinterpret_cast<const GLchar*>(
      background_fragment_file.GetFileData().data()
  );
  glShaderSource(background_fragment_shader, 1, &background_fragment_source, nullptr);
  glCompileShader(background_fragment_shader);
  
  // Shader Program
  std::uint32_t shader_program{glCreateProgram()};
  glAttachShader(shader_program, background_vertex_shader);
  glAttachShader(shader_program, background_fragment_shader);
  glLinkProgram(shader_program);
  glUseProgram(shader_program);

  glDeleteShader(background_vertex_shader);
  glDeleteShader(background_fragment_shader);
  
  // Layout 0: Colour: 
  glVertexAttribPointer(
      0, // Layout num
      3, 
      GL_FLOAT, 
      GL_FALSE, 
      5 * sizeof(float), 
      (void*)0
  );
  glEnableVertexAttribArray(0);  
  
  // Layout 1: UV: 
  glVertexAttribPointer(
      1, // Layout num
      2, // Num indexes
      GL_FLOAT, 
      GL_FALSE, 
      5 * sizeof(float), 
      (void*)(3 * sizeof(float))
  );
  glEnableVertexAttribArray(1);  
  glBindVertexArray(0);
  
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
      else if (event.type == SDL_EVENT_WINDOW_RESIZED)
      {
        int w {0};
        int h {0};
        SDL_GetWindowSize(
            current_window.ptr(), 
            &w, 
            &h 
        );
        glViewport(0, 0, w, h);
      }
    }

    // Main Loop.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shader_program);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glUniform1i(glGetUniformLocation(shader_program, "texture1"), 0);  // texture unit 0
    
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    SDL_GL_SwapWindow(current_window.ptr());
  }
  
  SDL_Quit();

  return 0;
};
