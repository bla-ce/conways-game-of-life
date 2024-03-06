#include <iostream>
#include <unistd.h>

constexpr int GRID_WIDTH{80};
constexpr int GRID_HEIGHT{24};

void clear_window()
{
  std::cout << "\x1b[2J" ;
}

int main()
{
  for(int n{1}; n < 10; n++)
  {
    clear_window();
    for(int col{}; col <= GRID_WIDTH; col++)
    {
      for(int row{}; row <= GRID_HEIGHT; row++)
      {
        std::cout << "\x1b[" << row+1 << ';' << col+1 << "H";
        std::cout << ((row + col) % n == 0 ? '0': '1');
      }
    }
    usleep(100000);
  }

  return 0;
}
