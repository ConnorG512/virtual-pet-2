#pragma once

#include <cstdint>

namespace Gameplay {
class Statistic {
public:
  Statistic(std::int32_t current_stat = 25000,
            std::int32_t maximum_stat = 50000);
  auto increaseStat(std::int32_t increase_amount) noexcept -> void;
  auto reduceStat(std::int32_t reduce_amount) noexcept -> std::int32_t;

private:
  std::int32_t max_{50000};
  std::int32_t current_{250000};
};
} // namespace Gameplay
