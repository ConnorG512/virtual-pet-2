#pragma once

#include "gameplay/statistic.hpp"

namespace Gameplay {
class Pet {
public:
  Pet() = default;
  ~Pet() = default;

  Statistic hunger_{};
  Statistic entertainment_{};

private:
};
} // namespace Gameplay
