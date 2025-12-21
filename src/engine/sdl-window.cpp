#include "engine/sdl-window.hpp"
#include "glad/glad.h"
#include "engine/sdl-attributes.hpp"

#include <cassert>
#include <print>

Engine::Window::Window(std::pair<std::int32_t, std::int32_t> dimensions)
    : screen_dimensions_{dimensions} 
{
}

auto Engine::Window::ptr() const noexcept -> SDL_Window * {
  return window_instance_.get();
}

auto Engine::Window::resetDimentions() const noexcept -> void {
  SDL_SetWindowSize(window_instance_.get(), screen_dimensions_.first,
                    screen_dimensions_.second);
}

auto Engine::Window::getCurrentDimensions() const noexcept
    -> std::pair<std::int32_t, std::int32_t> {
  return screen_dimensions_;
}

