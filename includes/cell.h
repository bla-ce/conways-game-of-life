#ifndef CELL_H
#define CELL_H

class Cell
{
private:
  bool alive;
public:
  Cell(); 

  void set_alive(const bool state);

  void draw(const int row, const int col) const;

  bool is_alive() const;
};

#endif

