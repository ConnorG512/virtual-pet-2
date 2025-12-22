#include "engine/opengl/shader-program.hpp"
#include "glad/glad.h"

Engine::OGL::ShaderProgram::ShaderProgram(std::vector<std::uint32_t> shaders)
  : id_{glCreateProgram()} 
{
  compileShaders(shaders);
  attachShaders(shaders);
  
  glLinkProgram(id_);

  deleteShaders(shaders);
}

auto Engine::OGL::ShaderProgram::compileShaders(std::vector<std::uint32_t> shaders) const noexcept -> void
{
  for (const auto shader : shaders)
  {
    glCompileShader(shader);
  }
}

auto Engine::OGL::ShaderProgram::attachShaders(std::vector<std::uint32_t> shaders) const noexcept -> void
{
  for (const auto shader : shaders)
  {
    glAttachShader(id_, shader);
  }
}

auto Engine::OGL::ShaderProgram::deleteShaders(std::vector<std::uint32_t> shaders) const noexcept -> void
{
  for (const auto shader : shaders)
  {
    glDeleteShader(shader);
  }
}
