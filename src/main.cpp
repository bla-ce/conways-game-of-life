#include <iostream>
#include <unistd.h>

#include "../includes/grid.h"

int main()
{
  std::cout << "Welcome to Conway's Game of Life!\n";
  std::cout << "Press Enter to start the simulation...\n";
  std::cin.get();

  // Create Grid
  Grid grid{};

  // Randomly Populate Grid
  grid.populate_grid();
  grid.display();

  while(true) 
  {
    usleep(50000);
    grid.next_generation();
    grid.display();
  }

  return 0;
}
