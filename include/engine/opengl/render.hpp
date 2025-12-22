#pragma once 

#include "glad/glad.h"

namespace Engine::OGL 
{
  auto clearScreen(
      GLfloat red = 0.0f, GLfloat green = 0.0f, GLfloat blue = 0.0f, GLbitfield mask = GL_COLOR_BUFFER_BIT) noexcept -> void;
}
