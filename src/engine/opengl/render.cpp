#include "engine/opengl/render.hpp"

auto Engine::OGL::clearScreen(
    GLfloat red, GLfloat green, GLfloat blue, GLbitfield mask) noexcept -> void
{
  glClearColor(red, green, blue, 1.0f);
  glClear(mask);
}
