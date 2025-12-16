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
  auto createFragment(const char* file_path) noexcept -> std::uint32_t
  {
    assert(file_path != nullptr);

    std::uint32_t fragment_shader{glCreateShader(GL_FRAGMENT_SHADER)};
    Engine::Utils::File background_fragment_file(file_path);
    
    const GLchar *background_fragment_source = reinterpret_cast<const GLchar *>(
        background_fragment_file.GetFileData().data());
    
    glShaderSource(fragment_shader, 1, &background_fragment_source,
                   nullptr);
    glCompileShader(fragment_shader);
    
    return fragment_shader;
  };
}
