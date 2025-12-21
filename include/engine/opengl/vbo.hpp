#pragma once 

#include "glad/glad.h"

#include <span>
#include <cstdint>
#include <cassert>

namespace Engine::OGL 
{
  template<typename BufferType>
  class VBO 
  {
    public:
      VBO(std::span<const BufferType> vertex_buffer)
        : vbo_{bindAndGenVbo()} 
      {
        createBuffer(vertex_buffer);
      }

    private:
      std::uint32_t vbo_{0};
      
      auto bindAndGenVbo() noexcept -> void
      {
        glGenBuffers(1, &vbo_);
      }

      auto createBuffer(std::span<const BufferType> vertex_buffer) noexcept -> void
      {
        assert(vertex_buffer.data() != nullptr);
        glBufferData(GL_ARRAY_BUFFER,
                     vertex_buffer.size() * sizeof(BufferType),
                     vertex_buffer.data(),
                     GL_STATIC_DRAW);
      }
  };
}
