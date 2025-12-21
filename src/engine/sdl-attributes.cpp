#include "engine/sdl-attributes.hpp"

Engine::Attributes::Attributes()
{
  for(const auto& [name, value]: attrib_list_)
    SDL_GL_SetAttribute(name, value);
}
