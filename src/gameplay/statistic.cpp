#include "gameplay/statistic.hpp"

#include <cassert>

Gameplay::Statistic::Statistic(std::int32_t current_stat, std::int32_t maximum_stat)
  : max_{maximum_stat}
  , current_{current_stat} 
{
  assert(current_ > 0);
  assert(max_ > 0);
}

auto Gameplay::Statistic::increaseStat(std::int32_t increase_amount) noexcept -> void
{
  current_ += increase_amount;
  if(current_ > max_)
  {
    current_ = max_;
  }
}

auto Gameplay::Statistic::reduceStat(std::int32_t reduce_amount) noexcept -> std::int32_t 
{
  current_ -= reduce_amount;
  if(current_ < 0)
  {
    current_ = 0;
  }
  
  return current_;
}
