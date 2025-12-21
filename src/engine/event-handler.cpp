#include "engine/event-handler.hpp"
#include "glad/glad.h"

#include <cassert>

auto Engine::EventHandler::event_loop() noexcept -> bool
{
  while(running_ == true)
  {
    while(SDL_PollEvent(&event_))
    {
      if(event_.type == SDL_EVENT_QUIT)
      {
        running_ = false;
        return running_;
      }
    }
  }
  return running_;
}

auto Engine::EventHandler::NewWindowDimensions(SDL_Window *window) const noexcept -> 
  std::optional<std::pair<std::uint32_t, std::uint32_t>>
{
  assert(window != nullptr);

  if(event_.type == SDL_EVENT_WINDOW_RESIZED)
  {
    int w{}, h{};
    SDL_GetWindowSize(window, &w, &h);
    
    return std::pair<std::uint32_t, std::uint32_t>{w,h};
  }
  return std::nullopt;
}
