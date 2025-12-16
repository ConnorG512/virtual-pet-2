#include "engine/sdl-window.hpp"
#include "glad/glad.h"
#include "engine/sdl-attributes.hpp"

#include <cassert>
#include <print>

Engine::SDL::Window::Window(std::pair<std::int32_t, std::int32_t> dimensions)
    : screen_dimensions_{dimensions} {
  for (const auto &[attribute, value] : ::SDL::ATTRIB_LIST) {
    SDL_GL_SetAttribute(attribute, value);
    std::println("Attribute: {0}, Value: {1}.", static_cast<int>(attribute),
                 value);
  }

  const auto window_result = createWindow();
  if (!window_result.has_value()) {
    throw std::runtime_error(window_result.error());
  } else {
    window_instance_.reset(window_result.value());
  }

  context_.reset(SDL_GL_CreateContext(window_instance_.get()));
  assert(context_ != nullptr);

  if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
    throw std::runtime_error("Failed to load GLAD!");
  }
}

auto Engine::SDL::Window::ptr() const noexcept -> SDL_Window * {
  return window_instance_.get();
}

auto Engine::SDL::Window::resetDimentions() const noexcept -> void {
  SDL_SetWindowSize(window_instance_.get(), screen_dimensions_.first,
                    screen_dimensions_.second);
}

auto Engine::SDL::Window::getCurrentDimensions() const noexcept
    -> std::pair<std::int32_t, std::int32_t> {
  return screen_dimensions_;
}

auto Engine::SDL::Window::createWindow() const noexcept
    -> std::expected<SDL_Window *, std::string> {
  const auto [width, height] = screen_dimensions_;

  const auto result{SDL_CreateWindow("Virtual Pet 2", width, height,
                                     SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)};
  if (result == nullptr) {
    return std::unexpected(
        std::format("Failed to created SDL Window! Error: {}", SDL_GetError()));
  }

  assert(result != nullptr);
  return result;
}
