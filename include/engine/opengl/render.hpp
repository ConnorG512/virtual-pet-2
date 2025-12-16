#pragma once 

#include "glad/glad.h"
#include "engine/file-object.hpp"

#include <cstdint>
#include <span>
#include <cassert>

namespace Engine::OGL 
{
  template <typename T>
  auto bindVbo(std::span<const T> vertex_buffer) noexcept -> void 
  {
    assert(vertex_buffer.data() != nullptr);

    std::uint32_t VBO{};
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,
                 vertex_buffer.size() * sizeof(T),
                 vertex_buffer.data(),
                 GL_STATIC_DRAW);
  };
  
  // Shader: 
  enum class Shader 
  {
    vertex, 
    fragment,
  };
  
  template <Engine::OGL::Shader shader_type>
  auto createShader(const char* file_path) noexcept -> std::uint32_t
  {
    assert(file_path != nullptr);
    
    Engine::Utils::File shader_file(file_path);

    if constexpr (shader_type == Engine::OGL::Shader::vertex)
    {
      std::uint32_t shader{glCreateShader(GL_VERTEX_SHADER)};

      const GLchar * shader_source = reinterpret_cast<const GLchar *>(
          shader_file.GetFileData().data());
      
      glShaderSource(
          shader, 1, &shader_source,
          reinterpret_cast<const GLint *>(&shader_file.size()));

      glCompileShader(shader);
      return shader;
    }
    else if constexpr (shader_type == Engine::OGL::Shader::fragment)
    {
      std::uint32_t shader{glCreateShader(GL_FRAGMENT_SHADER)};

      const GLchar * shader_source = reinterpret_cast<const GLchar *>(
          shader_file.GetFileData().data());
      
      glShaderSource(shader, 1, &shader_source,
                     nullptr);
      glCompileShader(shader);
      
      return shader;
    }
    else 
    {
      static_assert("Invalid shader type!");
    }
  }
}
