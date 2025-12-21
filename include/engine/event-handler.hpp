#pragma once 

#include "user-input.hpp"

#include <SDL3/SDL.h>
#include <utility>
#include <cstddef>

namespace Engine 
{
class EventHandler 
{
  public: 
    
    auto event_loop() noexcept -> bool;
    auto NewWindowDimensions(SDL_Window *window) const noexcept -> 
      std::optional<std::pair<std::uint32_t, std::uint32_t>>;

  private:
    SDL_Event event_{};
    InputHandler user_input{event_};
    bool running_{true};
};
}
