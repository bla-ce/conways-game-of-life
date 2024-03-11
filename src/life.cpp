#include <random>

int generate_random(int min, int max)
{
  std::mt19937 mt{ std::random_device{}() };
  std::uniform_int_distribution rand{min, max};

  return rand(mt);
}
