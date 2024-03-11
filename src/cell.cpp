#include "../includes/life.h"
#include "../includes/cell.h"
#include <iostream>

Cell::Cell() : alive(false){}

void Cell::set_alive(const bool state)
{
  alive = state;
}

void Cell::draw(const int row, const int col) const
{
  std::cout << "\x1b[" << row+1 << ";" << col+1 << 'H';
  std::cout << (alive ? LIVE_CELL : DEAD_CELL);
}


bool Cell::is_alive() const{ return alive; }
