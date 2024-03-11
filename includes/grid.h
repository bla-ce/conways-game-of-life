#include "cell.h"
#include "life.h"

class Grid
{
 private:
  // Initialize grid with 2-dim array of cells
  Cell cells[GRID_ROWS+2][GRID_COLS+2]; // add 2 for empty borders
public:
  Grid();

  /*
  * Function: Randomly populate grid with alive/dead cells
  */
  void populate_grid();

  /*
  * Function: Create copy of updated cells 
  */
  void next_generation();

  /*
  * Function: update grid cells with next generation
  * Params: next -> next generation of cells
  */
  void update(Grid& next);

  /*
  * Function: returns the number of alive neighbours
  * Params: Column and row of the cell
  * Return: int -> number of alive neighbours
  */
  int find_neighbours(const int row, const int col) const;

  /*
  * Function: display grid on screen
  */
  void display() const;
};
