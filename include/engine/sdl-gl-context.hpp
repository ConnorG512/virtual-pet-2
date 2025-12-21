#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <expected>
#include <string>

namespace Engine 
{
  class SDLGLContext 
  {
    public:
      SDLGLContext(SDL_Window* window_instance);
    private:
    std::unique_ptr<SDL_GLContextState, decltype(&SDL_GL_DestroyContext)>
        context_{nullptr, &SDL_GL_DestroyContext};

    auto createContext(SDL_Window* window_instance) noexcept -> 
      std::expected<void, std::string>; 
  };
}
