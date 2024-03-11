#ifndef CELL_H
#define CELL_H

class Cell
{
private:
  bool alive;
public:
  Cell(); 

  /*
  * Function: change alive boolean
  * Params: boolean state
  */
  void set_alive(const bool state);

  /*
  * Function: Draw cell on the screen
  * Params: Row and column of the screen
  */
  void draw(const int row, const int col) const;

  /*
  * Function: Return cell state
  * Return : state -> boolean
  */
  bool is_alive() const;
};

#endif

