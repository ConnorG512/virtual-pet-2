#pragma once 

#include "glad/glad.h"
#include "engine/file-object.hpp"

#include <cstdint>
#include <span>
#include <cassert>
#include <vector>

namespace Engine::OGL 
{
  // VBO
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
  }

  // VAO
  auto createVao() noexcept -> std::uint32_t;
  
  // Shader: 
  enum class Shader 
  {
    vertex, 
    fragment,
  };
  
  struct ProgramProperties 
  {
    const char* vertex_shader_path {};
    const char* fragment_shader_path {};
    std::uint32_t vertex_shader{};
    std::uint32_t fragment_shader{};
  };
  auto createProgram(const ProgramProperties& properties) noexcept -> std::uint32_t;
  auto attachAndLinkToProgram(std::uint32_t program, std::vector<std::uint32_t> shader_list) noexcept -> void;
  auto deleteShaders(std::vector<std::uint32_t> shader_list) noexcept -> void;
}
