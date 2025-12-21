#include "engine/opengl/vao.hpp"
#include "glad/glad.h"

Engine::VAO::VAO()
{
  glGenVertexArrays(1, &vao_);
  glBindVertexArray(vao_);
}

auto Engine::VAO::get() const -> std::uint32_t
{
  return vao_;
}
