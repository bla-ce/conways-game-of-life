#ifndef LIFE_H
#define LIFE_H

// Grid size
constexpr int GRID_ROWS{70};
constexpr int GRID_COLS{245};

// Display Cell
constexpr char LIVE_CELL { 'O' };
constexpr char DEAD_CELL { ' ' };

int generate_random(int min, int max);

#endif
