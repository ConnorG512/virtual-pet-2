#include "engine/opengl/render.hpp"

auto Engine::OGL::createVao() noexcept -> std::uint32_t 
{
  std::uint32_t VAO{};
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  return VAO;
}
