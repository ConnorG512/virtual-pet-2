#pragma once

#include "engine/sdl-window.hpp"
#include "engine/event-handler.hpp"
#include "glad/glad.h"

namespace Gameplay 
{
class Init
{
  public: 
    Init();
    ~Init() = default;

    auto loop() noexcept -> void;

  private:
    Engine::Window game_window_{};
    Engine::EventHandler event_handler_{};
};
}
