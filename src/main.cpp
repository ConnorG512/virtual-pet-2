#include "gameplay/init-game.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>

auto main() -> int {
  SDL_Init(SDL_INIT_VIDEO);
  
  Gameplay::Init game_init{};
  game_init.loop();

  SDL_Quit();
  return 0;
};
