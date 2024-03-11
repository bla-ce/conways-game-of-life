#include "cell.h"
#include "life.h"

class Grid
{
 private:
  Cell cells[GRID_ROWS+2][GRID_COLS+2]; // add 2 for empty borders
public:
  Grid();

  void populate_grid();

  void next_generation();

  void update(Grid& next);

  int find_neighbours(const int row, const int col) const;

  void display() const;
};
