#include <iostream>
#include <unistd.h>

#include "../includes/grid.h"

int main()
{ 
  // Create Grid
  Grid grid{};

  grid.clear();

  std::cout << "Welcome to Conway's Game of Life!\n";
  std::cout << "Press enter key to start setting up the simulation" << '\n';
  std::cin.get();

  std::string generation_probability{};
  std::cout << "\tProabability for a cell to be alive at generation 1 (Enter 20 for 20%): ";
  std::cin >> generation_probability;

  std::string birth_parameter{};
  std::cout << "\n\tSimulation Parameters:\n\tFor each parameter, pleaser enter the corresponding number of neighbours required to satisfy the parameter\n";
  std::cout << "\tBirth Condition (ex: B23): B";
  std::cin >> birth_parameter;

  std::string survive_parameter{};
  std::cout << "\tSurvive Condition (ex: S3): S";
  std::cin >> survive_parameter;


  // Randomly Populate Grid
  grid.populate_grid(generation_probability);

  // Display grid
  grid.display();

  // Simulation
  while(true) 
  {
    usleep(50000);

    // Update grid to next generation
    grid.next_generation(birth_parameter, survive_parameter);

    // Display next generation
    grid.display();
  }

  return 0;
}
