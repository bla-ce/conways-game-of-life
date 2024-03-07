#ifndef LIVE_H
#define LIVE_H

constexpr char DEAD_CELL { ' ' };
constexpr char LIVE_CELL { 'X' };

constexpr int GRID_ROWS { 23 };
constexpr int GRID_COLS { 79 };

// If live cell has less than 2 or more than 3 live neighbours, becomes dead cell
constexpr int MIN_NEIGHBORS { 2 }; 
constexpr int MAX_NEIGHBORS { 3 }; 

// If dead cell has 3 live neighbours, becomes live cell
constexpr int REPRODUCTION_N { 3 };

#endif
