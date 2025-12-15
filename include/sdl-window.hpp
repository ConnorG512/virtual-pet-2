#pragma once 

#include <memory>
#include <SDL3/SDL.h>

namespace Engine::SDL {
  class Window {
    public:
      explicit Window(std::pair<std::int32_t, std::int32_t> dimensions = {1600, 900});

      auto ptr() const noexcept -> SDL_Window*;

    private:
      std::unique_ptr<SDL_GLContextState, decltype(&SDL_GL_DestroyContext)> context_ {nullptr, &SDL_GL_DestroyContext};
      std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_instance_{
      nullptr, &SDL_DestroyWindow};
  };
}
