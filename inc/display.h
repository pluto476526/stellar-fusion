#ifndef DISPLAY_H
#define DISPLAY_H

#include "constellation.h"

#define GRID_WIDTH 80
#define GRID_HEIGHT 30
#define EMPTY_CHAR '.'

void init_grid(void);
void clear_grid(void);
void place_star(int x, int y, char symbol);
void draw_line(int x1, int y1, int x2, int y2, char symbol);
void render_constellation(const Constellation* constellation);
void render_grid(void);

#endif
