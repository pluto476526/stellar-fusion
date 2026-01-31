#ifndef CONSTELLATION_H
#define CONSTELLATION_H

// Star structure - basic unit of a constellation
typedef struct {
    int x;          // X coordinate (0-based)
    int y;          // Y coordinate (0-based)
    char symbol;    // Character to display
} Star;

// Line structure to connect stars
typedef struct {
    int from_star;  // Index of starting star in constellation
    int to_star;    // Index of ending star in constellation
    char symbol;    // Character for the line
} StarLine;

// Constellation structure - collection of stars with connecting lines
typedef struct {
    const char* name;
    const Star* stars;
    int star_count;
    const StarLine* lines;
    int line_count;
} Constellation;

// Available constellations
const Constellation* get_constellation(int index);
int get_constellation_count(void);

#endif
