#include "sdl-window.hpp"
#include "glad/glad.h"

#include <cstdint>

auto main() -> int 
{
  Engine::SDL::Window current_window{};

  bool is_running {true};
  while(is_running)
  {
    SDL_Event event{};
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_EVENT_QUIT)
        is_running = false;
      
      // Main Loop.
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      SDL_GL_SwapWindow(current_window.ptr());
    }
  }

  SDL_Quit();

  return 0;
};
