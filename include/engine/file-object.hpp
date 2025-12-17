#pragma once

#include "glad/glad.h"

#include <span>
#include <cstddef>
#include <expected>
#include <string>
#include <memory>
#include <SDL3/SDL_stdinc.h>

namespace Engine 
{
  class File 
  {
    public:
      File(const char* file_path);
      ~File() = default;
      
      auto GetData() noexcept -> std::span<const std::byte>;
    
    private:
      std::unique_ptr<void, decltype(&SDL_free)> data_ {nullptr, &SDL_free}; 
      std::size_t size_ {0};
  };
}
