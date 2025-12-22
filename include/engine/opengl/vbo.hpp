#pragma once 

#include "glad/glad.h"
#include "engine/opengl/gl-types.hpp"

#include <span>
#include <cstdint>
#include <cassert>

namespace Engine::OGL 
{
  class VBO 
  {
    public:
      VBO(std::span<const Engine::OGL::BufferType> vertex_buffer)
      {
        bindAndGenVbo();
        createBuffer(vertex_buffer);
      }
      auto get() const -> std::uint32_t
      {
        return vbo_;
      }

    private:
      std::uint32_t vbo_{0};
      
      auto bindAndGenVbo() noexcept -> void
      {
        glGenBuffers(1, &vbo_);
      }

      auto createBuffer(std::span<const Engine::OGL::BufferTypee> vertex_buffer) noexcept -> void
      {
        assert(vertex_buffer.data() != nullptr);
        glBufferData(GL_ARRAY_BUFFER,
                     vertex_buffer.size() * sizeof(BufferType),
                     vertex_buffer.data(),
                     GL_STATIC_DRAW);
      }
  };
}
