#include "engine/opengl/render.hpp"

auto Engine::OGL::createVao() noexcept -> std::uint32_t 
{
  std::uint32_t VAO{};
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  return VAO;
}

auto Engine::OGL::attachAndLinkToProgram(std::uint32_t program, std::vector<std::uint32_t> shader_list) noexcept -> void
{
  for(const auto shader : shader_list)
  {
    glAttachShader(program, shader);
  }
  
  glLinkProgram(program);
}

auto Engine::OGL::deleteShaders(std::vector<std::uint32_t> shader_list) noexcept -> void
{
  for(const auto shader : shader_list) 
  {
    glDeleteShader(shader);
  }
}
