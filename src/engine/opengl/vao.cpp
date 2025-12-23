#include "engine/opengl/vao.hpp"
#include "glad/glad.h"

Engine::OGL::VAO::VAO()
{
  glGenVertexArrays(1, &vao_);
  glBindVertexArray(vao_);
}

auto Engine::OGL::VAO::get() const -> std::uint32_t
{
  return vao_;
}
