#pragma once

#include "engine/sdl-window.hpp"
#include "engine/event-handler.hpp"
#include "engine/opengl/render-target.hpp"
#include "glad/glad.h"

namespace Gameplay 
{
class Init
{
  public: 
    auto loop() noexcept -> void;

  private:
    Engine::Window game_window_{};
    Engine::EventHandler event_handler_{};
    Engine::OGL::RenderTarget<float> render_target{};
};
}
