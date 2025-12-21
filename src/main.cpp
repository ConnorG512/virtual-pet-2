#include "gameplay/init-game.hpp"

#include <SDL3/SDL.h>

auto main() -> int {
  
  Gameplay::Init game_init{};
  game_init.loop();

  SDL_Quit();
  return 0;
};
