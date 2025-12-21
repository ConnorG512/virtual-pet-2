#pragma once

#include <cstdint>

namespace Engine::OGL 
{
  class VAO 
  {
    public: 
      VAO();
      auto get() const -> std::uint32_t;
      
    private:
      std::uint32_t vao_{0};
  };
}
