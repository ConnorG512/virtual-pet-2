#pragma once 

#include <SDL3/SDL.h>
#include <optional>
#include <cstdint>

namespace Engine {
class InputHandler 
{
  public: 
    InputHandler(SDL_Event& event);

    auto performKeyPress() noexcept -> void;
  private:
    SDL_Event& event_instance_;
};
}
