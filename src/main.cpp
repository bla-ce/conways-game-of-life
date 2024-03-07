#include <random>
#include <iostream>
#include <unistd.h>

// Grid size
constexpr int GRID_ROWS{50};
constexpr int GRID_COLS{100};

// Display Cell
constexpr char LIVE_CELL { 'X' };
constexpr char DEAD_CELL { ' ' };

// Generate random number to know if cell is initially alive or dead
int generate_random(int min, int max)
{
  std::mt19937 mt{ std::random_device{}() };
  std::uniform_int_distribution rand{min, max};

  return rand(mt);
}

class Cell
{
private:
  bool alive;
public:
  Cell() : alive(false){}

  void set_alive(bool state)
  {
    alive = state;
  }
  
  void draw(int row, int col) const
  {
    std::cout << "\x1b[" << row+1 << ";" << col+1 << 'H';
    std::cout << (alive ? LIVE_CELL : DEAD_CELL);
  }

  bool is_alive() const{ return alive; }
};

class Grid
{
private:
  Cell cells[GRID_ROWS][GRID_COLS];
public:
  Grid()
  {
    for(int row{}; row < GRID_ROWS; row++)
    {
      for(int col{}; col < GRID_COLS; col++)
      {
        cells[row][col] = Cell();
      }
    } 
  }

  void populate_grid()
  {
   for(int row{}; row < GRID_ROWS; row++)
    {
      for(int col{}; col < GRID_COLS; col++)
      {
        cells[row][col].set_alive( (generate_random(1, 5) == 1 ? true : false) ); // populate grid with 20% chance of alive cell
      }
    }

  }

  void display() const
  {
    for(int row{}; row < GRID_ROWS; row++)
    {
      for(int col{}; col < GRID_COLS; col++)
      {
        cells[row][col].draw(row, col);
      }
    }

    std::cout << '\n';
  }

  void clear() const 
  {
    std::cout << "\x1b[2J";
  }
};

int main()
{
  // Create Grid
  Grid grid{};

  // Randomly Populate Grid
  for(int n{}; n < 1000; n++)
  {
    grid.clear();
    grid.populate_grid();
    grid.display();
    usleep(100000);
  }

  // Display Grid

  // loop
  // clear window
  // clean up
  // exit
  return 0;
}
