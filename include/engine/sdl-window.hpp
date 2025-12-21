#pragma once

#include "engine/sdl-attributes.hpp"
#include "engine/sdl-gl-context.hpp"

#include <SDL3/SDL.h>
#include <expected>
#include <memory>

namespace Engine {
class Window {
public:
  explicit Window(std::pair<std::int32_t, std::int32_t> dimensions = {1600,
                                                                      900});

  auto ptr() const noexcept -> SDL_Window *;
  auto resetDimentions() const noexcept -> void;
  auto getCurrentDimensions() const noexcept
      -> std::pair<std::int32_t, std::int32_t>;

private:
  auto createWindow() const noexcept
      -> std::expected<SDL_Window *, std::string>;
  auto createGLContext() noexcept 
    -> std::expected<void, std::string>;
  
  Engine::Attributes attributes{};
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_instance_{
      nullptr, &SDL_DestroyWindow};
  SDLGLContext context_{window_instance_.get()};
  std::pair<std::int32_t, std::int32_t> screen_dimensions_{1600, 900};
};
} // namespace Engine::SDL
