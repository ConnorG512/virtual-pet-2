#pragma once 

#include <memory>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>

namespace Engine {
  class Image 
  {
    public:
      Image(const char* file_path);
      
      auto data() noexcept -> const SDL_Surface*; 
    private:
      std::unique_ptr<SDL_Surface, decltype(&SDL_DestroySurface)> image_ {nullptr, &SDL_DestroySurface}; 
  };
}
