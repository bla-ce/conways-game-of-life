#include <iostream>
#include <unistd.h>

#include "../includes/grid.h"

int main()
{
  std::cout << "Welcome to Conway's Game of Life!\n";

  // Create Grid
  Grid grid{};

  // Randomly Populate Grid
  grid.populate_grid();

  // Display grid
  grid.display();

  // Simulation
  while(true) 
  {
    usleep(50000);

    // Update grid to next generation
    grid.next_generation();

    // Display next generation
    grid.display();
  }

  return 0;
}
