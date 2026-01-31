#include "constellation.h"

// Helper macro to get line character based on slope
#define LINE_CHAR(x1, y1, x2, y2) (abs(x2-x1) > abs(y2-y1) ? '-' : (abs(y2-y1) > abs(x2-x1) ? '|' : '/'))

// Big Dipper (Ursa Major)
static const Star big_dipper[] = {
    {15, 5, '*'}, {22, 8, '*'}, {29, 11, '*'}, {36, 13, '*'},
    {43, 15, '*'}, {50, 16, '*'}, {57, 17, '*'}, {33, 8, '+'},
    {40, 10, '+'}, {47, 12, '+'}
};

static const StarLine big_dipper_lines[] = {
    {0, 1, '-'}, {1, 2, '-'}, {2, 3, '-'}, {3, 4, '-'},
    {4, 5, '-'}, {5, 6, '-'}, {2, 7, '\\'}, {3, 8, '\\'},
    {4, 9, '\\'}
};

// Orion
static const Star orion[] = {
    {40, 5, '*'}, {35, 8, '*'}, {45, 8, '*'}, {40, 11, '+'},
    {30, 14, '*'}, {50, 14, '*'}, {40, 17, '*'}, {35, 20, '*'},
    {45, 20, '*'}, {40, 23, '*'}
};

static const StarLine orion_lines[] = {
    {0, 1, '/'}, {0, 2, '\\'}, {1, 3, '/'}, {2, 3, '\\'},
    {3, 6, '|'}, {4, 6, '/'}, {5, 6, '\\'}, {6, 7, '/'},
    {6, 8, '\\'}, {7, 9, '\\'}, {8, 9, '/'}
};

// Cassiopeia
static const Star cassiopeia[] = {
    {50, 5, '*'}, {40, 10, '+'}, {55, 15, '*'}, {35, 20, '+'},
    {60, 25, '*'}, {45, 28, '+'}
};

static const StarLine cassiopeia_lines[] = {
    {0, 1, '/'}, {0, 2, '\\'}, {2, 3, '/'}, {2, 4, '\\'},
    {4, 5, '/'}
};

// Southern Cross (Crux)
static const Star crux[] = {
    {40, 10, '*'}, {40, 15, '*'}, {40, 20, '*'}, {35, 15, '*'},
    {45, 15, '*'}, {30, 15, '+'}, {50, 15, '+'}
};

static const StarLine crux_lines[] = {
    {0, 1, '|'}, {1, 2, '|'}, {1, 3, '-'}, {1, 4, '-'},
    {3, 5, '-'}, {4, 6, '-'}
};

// Cygnus
static const Star cygnus[] = {
    {20, 5, '*'}, {30, 10, '*'}, {40, 15, '*'}, {50, 20, '*'},
    {30, 20, '*'}, {20, 25, '*'}, {10, 18, '*'}, {35, 25, '*'},
    {45, 10, '*'}
};

static const StarLine cygnus_lines[] = {
    {0, 1, '/'}, {1, 2, '/'}, {2, 3, '/'}, {1, 4, '\\'},
    {4, 5, '/'}, {4, 6, '\\'}, {2, 7, '\\'}, {1, 8, '-'}
};

// Leo
static const Star leo[] = {
    {60, 5, '*'}, {55, 10, '*'}, {50, 15, '*'}, {45, 20, '*'},
    {40, 25, '*'}, {35, 28, '*'}, {60, 15, '+'}, {65, 20, '*'},
    {70, 25, '*'}, {75, 28, '*'}
};

static const StarLine leo_lines[] = {
    {0, 1, '/'}, {1, 2, '/'}, {2, 3, '/'}, {3, 4, '/'},
    {4, 5, '/'}, {1, 6, '\\'}, {6, 7, '/'}, {7, 8, '/'},
    {8, 9, '/'}
};

// Taurus
static const Star taurus[] = {
    {15, 10, '*'}, {25, 15, '*'}, {35, 20, '*'}, {45, 15, '*'},
    {55, 10, '*'}, {35, 25, '*'}, {30, 28, '*'}, {40, 28, '*'},
    {35, 30, '*'}, {25, 18, '+'}, {45, 18, '+'}
};

static const StarLine taurus_lines[] = {
    {0, 1, '/'}, {1, 2, '/'}, {2, 3, '\\'}, {3, 4, '\\'},
    {2, 5, '|'}, {5, 6, '/'}, {5, 7, '\\'}, {6, 8, '\\'},
    {7, 8, '/'}, {1, 9, '|'}, {3, 10, '|'}
};

// Scorpius
static const Star scorpius[] = {
    {65, 5, '*'}, {60, 8, '*'}, {55, 11, '*'}, {50, 14, '*'},
    {45, 17, '*'}, {40, 20, '*'}, {35, 23, '*'}, {30, 20, '*'},
    {25, 17, '*'}, {20, 14, '*'}, {15, 11, '*'}, {10, 8, '*'}
};

static const StarLine scorpius_lines[] = {
    {0, 1, '/'}, {1, 2, '/'}, {2, 3, '/'}, {3, 4, '/'},
    {4, 5, '/'}, {5, 6, '/'}, {5, 7, '\\'}, {7, 8, '\\'},
    {8, 9, '\\'}, {9, 10, '\\'}, {10, 11, '\\'}
};

// Gemini
static const Star gemini[] = {
    {20, 10, '*'}, {20, 15, '*'}, {20, 20, '*'}, {15, 23, '*'},
    {25, 23, '*'}, {10, 18, '+'}, {30, 18, '+'},
    {50, 10, '*'}, {50, 15, '*'}, {50, 20, '*'}, {45, 23, '*'},
    {55, 23, '*'}, {40, 18, '+'}, {60, 18, '+'}
};

static const StarLine gemini_lines[] = {
    {0, 1, '|'}, {1, 2, '|'}, {2, 3, '/'}, {2, 4, '\\'},
    {1, 5, '-'}, {1, 6, '-'},
    {7, 8, '|'}, {8, 9, '|'}, {9, 10, '/'}, {9, 11, '\\'},
    {8, 12, '-'}, {8, 13, '-'}
};

// Sagittarius
static const Star sagittarius[] = {
    {10, 15, '*'}, {20, 12, '*'}, {30, 9, '*'}, {40, 9, '*'},
    {50, 12, '*'}, {60, 15, '*'}, {40, 18, '*'}, {30, 21, '*'},
    {20, 24, '*'}, {10, 27, '*'}, {50, 21, '*'}, {60, 24, '*'}
};

static const StarLine sagittarius_lines[] = {
    {0, 1, '/'}, {1, 2, '/'}, {2, 3, '-'}, {3, 4, '\\'},
    {4, 5, '/'}, {3, 6, '|'}, {6, 7, '/'}, {7, 8, '/'},
    {8, 9, '/'}, {6, 10, '\\'}, {10, 11, '/'}
};

// Capricornus
static const Star capricornus[] = {
    {15, 10, '*'}, {25, 15, '*'}, {35, 18, '*'}, {45, 18, '*'},
    {55, 15, '*'}, {65, 10, '*'}, {55, 22, '*'}, {45, 25, '*'},
    {35, 26, '*'}, {25, 25, '*'}, {15, 22, '*'}
};

static const StarLine capricornus_lines[] = {
    {0, 1, '/'}, {1, 2, '/'}, {2, 3, '-'}, {3, 4, '\\'},
    {4, 5, '/'}, {4, 6, '|'}, {6, 7, '/'}, {7, 8, '/'},
    {8, 9, '/'}, {9, 10, '/'}
};

// Andromeda
static const Star andromeda[] = {
    {5, 15, '*'}, {15, 14, '*'}, {25, 13, '*'}, {35, 12, '*'},
    {45, 13, '*'}, {55, 14, '*'}, {65, 15, '*'}, {32, 17, '+'},
    {38, 17, '+'}, {35, 22, '*'}
};

static const StarLine andromeda_lines[] = {
    {0, 1, '\\'}, {1, 2, '\\'}, {2, 3, '\\'}, {3, 4, '/'},
    {4, 5, '/'}, {5, 6, '/'}, {3, 7, '|'}, {3, 8, '|'},
    {3, 9, '|'}
};

// Array of all constellations
static const Constellation constellations[] = {
    {"Big Dipper", big_dipper, 10, big_dipper_lines, 9},
    {"Orion", orion, 10, orion_lines, 11},
    {"Cassiopeia", cassiopeia, 6, cassiopeia_lines, 5},
    {"Southern Cross", crux, 7, crux_lines, 6},
    {"Cygnus", cygnus, 9, cygnus_lines, 8},
    {"Leo", leo, 10, leo_lines, 9},
    {"Taurus", taurus, 11, taurus_lines, 11},
    {"Scorpius", scorpius, 12, scorpius_lines, 11},
    {"Gemini", gemini, 14, gemini_lines, 12},
    {"Sagittarius", sagittarius, 12, sagittarius_lines, 11},
    {"Capricornus", capricornus, 11, capricornus_lines, 10},
    {"Andromeda", andromeda, 10, andromeda_lines, 9}
};

static const int constellation_count = 
    sizeof(constellations) / sizeof(Constellation);

const Constellation* get_constellation(int index) {
    if (index >= 0 && index < constellation_count) {
        return &constellations[index];
    }
    return &constellations[0]; // Return first as default
}

int get_constellation_count(void) {
    return constellation_count;
}
