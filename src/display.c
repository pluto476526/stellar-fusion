#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include "constellation.h"

static char grid[GRID_HEIGHT][GRID_WIDTH];

void init_grid(void) {
    clear_grid();
}

void clear_grid(void) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            grid[y][x] = EMPTY_CHAR;
        }
    }
}

void place_star(int x, int y, char symbol) {
    // Bounds checking
    if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT) {
        grid[y][x] = symbol;
    }
}

void draw_line(int x1, int y1, int x2, int y2, char symbol) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    
    while (1) {
        // Place line character if position is empty or contains a line character
        if (x1 >= 0 && x1 < GRID_WIDTH && y1 >= 0 && y1 < GRID_HEIGHT) {
            if (grid[y1][x1] == EMPTY_CHAR || grid[y1][x1] == symbol || 
                grid[y1][x1] == '-' || grid[y1][x1] == '|' || 
                grid[y1][x1] == '/' || grid[y1][x1] == '\\') {
                place_star(x1, y1, symbol);
            }
        }
        
        if (x1 == x2 && y1 == y2) break;
        
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y1 += sy;
        }
    }
}

void render_constellation(const Constellation* constellation) {
    clear_grid();
    
    // First draw all lines
    for (int i = 0; i < constellation->line_count; i++) {
        StarLine line = constellation->lines[i];
        if (line.from_star < constellation->star_count && 
            line.to_star < constellation->star_count) {
            Star star1 = constellation->stars[line.from_star];
            Star star2 = constellation->stars[line.to_star];
            draw_line(star1.x, star1.y, star2.x, star2.y, line.symbol);
        }
    }
    
    // Then draw stars (overwrites line endpoints)
    for (int i = 0; i < constellation->star_count; i++) {
        Star star = constellation->stars[i];
        place_star(star.x, star.y, star.symbol);
    }
    
    render_grid();
}

void render_grid(void) {
    // Coordinate markers for top
    printf("    ");
    for (int x = 0; x < GRID_WIDTH; x++) {
        if (x % 10 == 0) printf("%d", x/10);
        else if (x % 5 == 0) printf("·");
        else printf(" ");
    }
    printf("\n     ");
    for (int x = 0; x < GRID_WIDTH; x++) {
        printf("%d", x % 10);
    }
    printf("\n");
    
    // Top border
    printf("   ┌");
    for (int x = 0; x < GRID_WIDTH; x++) printf("─");
    printf("┐\n");
    
    // Grid content with side borders and coordinates
    for (int y = 0; y < GRID_HEIGHT; y++) {
        printf("%2d │", y);
        for (int x = 0; x < GRID_WIDTH; x++) {
            printf("%c", grid[y][x]);
        }
        printf("│");
        // Add coordinate markers on right every 5 rows
        if (y % 5 == 0 && y < 10) printf("  N");
        else if (y == GRID_HEIGHT/2) printf("  ─");
        else if (y == GRID_HEIGHT-1) printf("  S");
        printf("\n");
    }
    
    // Bottom border
    printf("   └");
    for (int x = 0; x < GRID_WIDTH; x++) printf("─");
    printf("┘\n");
    
    // Compass rose
    printf("    W");
    for (int x = 0; x < GRID_WIDTH-2; x++) printf(" ");
    printf("E \n");
}
