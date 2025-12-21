#include "engine/user-input.hpp"

#include <algorithm>
#include <array>
#include <print>

Engine::InputHandler::InputHandler(SDL_Event& event)
  : event_instance_{event} {}

auto Engine::InputHandler::performKeyPress() noexcept -> void 
{
  if (event_instance_.key.scancode == SDL_SCANCODE_F10) 
    std::println("F10 pressed!");
  else if (event_instance_.key.scancode == SDL_SCANCODE_F12) 
    std::println("F12 pressed!");
}
