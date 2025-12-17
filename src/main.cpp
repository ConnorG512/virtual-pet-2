#include "engine/errorbox.hpp"
#include "engine/file-object.hpp"
#include "glad/glad.h"
#include "engine/primitive-shapes.hpp"
#include "engine/sdl-window.hpp"
#include "engine/opengl/render.hpp"

#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>
#include <cstdint>
#include <print>

auto main() -> int {
  Engine::SDL::Window current_window{};
  glViewport(0, 0, current_window.getCurrentDimensions().first,
             current_window.getCurrentDimensions().second);

  // Genertating a texture
  SDL_Surface *texture_image{
      IMG_Load("assets/image/background/HomeScreen.png")};
  if (texture_image == nullptr) {
    Engine::ErrorBox::CreateErrorBox<Engine::ErrorBox::BoxType::error>(
        "Failed to load image texture!", current_window.ptr());
    return -1;
  }
  std::println("Texture loaded: H{0}W{1}", texture_image->h, texture_image->w);

  // Converting the image colour format:
  SDL_Surface *converted_texture_image{
      SDL_ConvertSurface(texture_image, SDL_PIXELFORMAT_RGBA32)};

  GLuint texture_id{0};
  glGenTextures(1, &texture_id);
  glBindTexture(GL_TEXTURE_2D, texture_id);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, converted_texture_image->w,
               converted_texture_image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE,
               converted_texture_image->pixels);
  // glGenerateMipmap(GL_TEXTURE_2D);

  SDL_DestroySurface(texture_image);
  SDL_DestroySurface(converted_texture_image);

  std::uint32_t VAO{Engine::OGL::createVao()};

  Engine::OGL::bindVbo<float>(Utils::BasicShapes::FULL_SCREEN_RECTANGLE);
  std::uint32_t shader_program {Engine::OGL::createProgram(Engine::OGL::ProgramProperties{
      .vertex_shader_path="src/shaders/default.vert",
      .fragment_shader_path="src/shaders/default.frag",
  })};
  
  //Engine::OGL::deleteShaders({background_vertex_shader, background_fragment_shader});

  // Layout 0: Colour:
  glVertexAttribPointer(0, // Layout num
                        3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // Layout 1: UV:
  glVertexAttribPointer(1, // Layout num
                        2, // Num indexes
                        GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  glBindVertexArray(0);

  bool is_running{true};
  while (is_running) {
    SDL_Event event{};
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT)
        is_running = false;
      else if (event.type == SDL_EVENT_KEY_DOWN)
        current_window.resetDimentions();
      else if (event.type == SDL_EVENT_WINDOW_RESIZED) {
        int w{0};
        int h{0};
        SDL_GetWindowSize(current_window.ptr(), &w, &h);
        glViewport(0, 0, w, h);
      }
    }

    // Main Loop.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shader_program);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glUniform1i(glGetUniformLocation(shader_program, "texture1"),
                0); // texture unit 0

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    SDL_GL_SwapWindow(current_window.ptr());
  }

  SDL_Quit();

  return 0;
};
