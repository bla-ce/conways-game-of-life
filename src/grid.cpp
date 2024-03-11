#include "../includes/life.h"
#include "../includes/grid.h"
#include <iostream>

Grid::Grid()
{
  for(int row{}; row < GRID_ROWS; row++)
  {
    for(int col{}; col < GRID_COLS; col++)
    {
      cells[row][col] = Cell();
    }
  } 
}

void Grid::populate_grid(std::string generation_probability)
{
  for(int row{1}; row < GRID_ROWS; row++)
  {
    for(int col{1}; col < GRID_COLS; col++)
    {
      cells[row][col].set_alive( (generate_random(1, 100 / std::stoi(generation_probability) ) == 1 ? true : false) ); // populate grid with 20% chance of alive cell
    }
  }
}

void Grid::next_generation(std::string birth_paramater, std::string survive_parameter)
{
  Grid next{ *this };
  // for each cell
  for(int row{1}; row < GRID_ROWS; row++)
  {
    for(int col{1}; col < GRID_COLS; col++)
    {
      int neighbours { find_neighbours(row, col) };

      if (cells[row][col].is_alive())
      {
        if(survive_parameter.find( std::to_string(neighbours) ) == std::string::npos)
        {
          next.cells[row][col].set_alive(false);
        }
      } else {
        if(birth_paramater.find( std::to_string(neighbours) ) != std::string::npos)
        {
          next.cells[row][col].set_alive(true);
        }
      }
    }
  }

  update(next);
}

void Grid::update(Grid& next)
{
  for(int row{1}; row < GRID_ROWS; row++)
  {
    for(int col{1}; col < GRID_COLS; col++)     
    {
      cells[row][col] = next.cells[row][col];
    }
  }
}

int Grid::find_neighbours(const int row, const int col) const
{
  int neighbours{};

  for(int xstep{-1}; xstep <= 1; xstep++)
  {
    for(int ystep{-1}; ystep <= 1; ystep++)
    {
      if(xstep == 0 && ystep == 0) continue;
      neighbours += (cells[row+xstep][col+ystep].is_alive() ? 1 : 0);
    }
  }

  return neighbours;
}

void Grid::display() const
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

void Grid::clear() const
{
  for(int row{1}; row < GRID_ROWS + 2; row++)
  {
    for(int col{1}; col < GRID_COLS + 2; col++)
    {
      std::cout << "\x1b[" << row << ";" << col << 'H';
      std::cout << ' ';
    }
  }

  std::cout << "\x1b[" << 1 << ";" << 1 << 'H';
}
