#include "gameplay/init-game.hpp"
#include "engine/file-object.hpp"
#include "engine/image.hpp"
#include "engine/primitive-shapes.hpp"
#include "engine/opengl/render.hpp"

#include <print>

// Init
//  glViewport(0, 0, game_window_.getCurrentDimensions().first,
//             game_window_.getCurrentDimensions().second);
//
//  Engine::Image texture_image{"assets/image/background/HomeScreen.png"};
//  std::println("Texture loaded: H{0}W{1}", texture_image.data()->h, texture_image.data()->w);
//
//  GLuint texture_id{0};
//  glGenTextures(1, &texture_id);
//  glBindTexture(GL_TEXTURE_2D, texture_id);
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//  // glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_image.data()->w,
//               texture_image.data()->h, 0, GL_RGBA, GL_UNSIGNED_BYTE,
//               texture_image.data()->pixels);
//  // glGenerateMipmap(GL_TEXTURE_2D);
//  
//  std::uint32_t VAO{Engine::OGL::createVao()};
//
//  Engine::OGL::bindVbo<float>(Utils::BasicShapes::FULL_SCREEN_RECTANGLE);
//  std::uint32_t shader_program {Engine::OGL::createProgram(Engine::OGL::ProgramProperties{
//      .vertex_shader_path="src/shaders/default.vert",
//      .fragment_shader_path="src/shaders/default.frag",
//  })};
//  
//  // Layout 0: Colour:
//  glVertexAttribPointer(0, // Layout num
//                        3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
//  glEnableVertexAttribArray(0);
//
//  // Layout 1: UV:
//  glVertexAttribPointer(1, // Layout num
//                        2, // Num indexes
//                        GL_FLOAT, GL_FALSE, 5 * sizeof(float),
//                        (void *)(3 * sizeof(float)));
//  glEnableVertexAttribArray(1);
//  glBindVertexArray(0);

// Draw
// Main Loop.
//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//glClear(GL_COLOR_BUFFER_BIT);
//
//glUseProgram(shader_program);
//glActiveTexture(GL_TEXTURE0);
//glBindTexture(GL_TEXTURE_2D, texture_id);
//glUniform1i(glGetUniformLocation(shader_program, "texture1"),
//  0); // texture unit 0
//
//glBindVertexArray(VAO);
//glDrawArrays(GL_TRIANGLES, 0, 6);
//SDL_GL_SwapWindow(current_window.ptr());

auto Gameplay::Init::loop() noexcept -> void
{
  while(event_handler_.event_loop())
  {
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(game_window_.ptr());
  }
}
