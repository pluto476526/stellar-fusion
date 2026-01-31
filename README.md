# Stellar Fusion: Terminal Constellations

![Stellar Fusion Demo](https://img.shields.io/badge/Stellar-Fusion-blue)
![C Programming](https://img.shields.io/badge/Language-C-00599C)
![Terminal Based](https://img.shields.io/badge/Terminal-Based-4D4D4D)
![License](https://img.shields.io/badge/License-MIT-green)

A beautiful terminal-based star chart program that displays 12 major constellations with connecting lines, creating accurate astronomical patterns using ASCII art.

## ✨ Features

- **12 Complete Constellations**: Big Dipper, Orion, Cassiopeia, Southern Cross, Cygnus, Leo, Taurus, Scorpius, Gemini, Sagittarius, Capricornus, Andromeda
- **Connected Stars**: Uses Bresenham's line algorithm to draw accurate connections between stars
- **Large Canvas**: 80x30 character grid for detailed constellation patterns
- **Smart Line Drawing**: Automatically selects appropriate line characters (`-`, `|`, `/`, `\`) based on slope
- **Interactive Menu**: Beautifully formatted 3-column selection interface
- **Random Mode**: Instantly view a random constellation
- **Coordinate System**: Full grid coordinates and compass directions
- **Statistics Display**: Shows star count, line count, and grid dimensions

## 🚀 Quick Start

### Prerequisites
- GCC compiler (or any C compiler)
- Terminal with UTF-8 support (for border characters)

### Compilation

```bash
# Clone or download the project
git clone https://github.com/yourusername/stellar-fusion.git
cd stellar-fusion

# Compile the program
gcc -std=c99 -o stellar_fusion main.c constellation.c display.c

# Run the program
./stellar_fusion
```

### For Windows
```bash
gcc -std=c99 -o stellar_fusion.exe main.c constellation.c display.c
stellar_fusion.exe
```

## 📁 Project Structure

```
stellar_fusion/
│
├── star.h              # Star and StarLine structures
├── constellation.h     # Constellation structure and API
├── display.h          # Display functions and grid constants
│
├── main.c             # Program entry point and user interface
├── constellation.c    # All 12 constellations with star coordinates
├── display.c         # Grid management and rendering logic
│
└── README.md         # This documentation
```

### File Descriptions

1. **star.h** - Defines the basic building blocks:
   - `Star` struct: Position and character for individual stars
   - `StarLine` struct: Connections between stars with line characters

2. **constellation.h** - Defines the constellation structure and API:
   - `Constellation` struct: Collection of stars and connecting lines
   - Functions to access constellations by index

3. **display.h** - Display configuration:
   - Grid dimensions (80x30)
   - Function prototypes for grid manipulation and rendering

4. **main.c** - User interface:
   - Interactive menu with 3-column layout
   - Input handling for constellation selection
   - Random constellation generator
   - Screen clearing and program flow control

5. **constellation.c** - Constellation data:
   - All 12 constellations with accurate star positions
   - Predefined connecting lines that form recognizable patterns
   - Automatic line character selection based on slope

6. **display.c** - Rendering engine:
   - Bresenham's line algorithm for smooth connections
   - Coordinate system with compass directions
   - Grid management with bounds checking
   - Beautiful border rendering with statistics

## 🎮 How to Use

1. Run the compiled program
2. View the menu showing all 12 constellations in a 3-column layout
3. Enter the number of the constellation you want to view
4. Or enter 'R' for a random constellation
5. Press Enter to view another constellation
6. Enter '0' to exit

### Example Session
```
╔══════════════════════════════════════════════════════════════╗
║                 STELLAR FUSION - CONSTELLATIONS              ║
╠══════════════════════════════════════════════════════════════╣
║                                                              ║
║  1. Big Dipper           6. Leo               11. Capricornus║
║  2. Orion                7. Taurus            12. Andromeda  ║
║  3. Cassiopeia           8. Scorpius                         ║
║  4. Southern Cross       9. Gemini                           ║
║  5. Cygnus              10. Sagittarius                      ║
║                                                              ║
╠══════════════════════════════════════════════════════════════╣
║  0. Exit                         R. Random Constellation    ║
╚══════════════════════════════════════════════════════════════╝

Select constellation (1-12, R for random, 0 to exit): 2
```

## 🌌 Constellation Details

Each constellation includes:

1. **Big Dipper** (Ursa Major) - The seven-star ladle, one of the most recognizable patterns
2. **Orion** - The Hunter with distinctive belt and sword
3. **Cassiopeia** - W-shaped queen constellation
4. **Southern Cross** (Crux) - Important navigation constellation
5. **Cygnus** - Northern Cross/Swan flying along the Milky Way
6. **Leo** - The Lion with sickle-shaped head
7. **Taurus** - The Bull with V-shaped face and horns
8. **Scorpius** - Scorpion with curved tail and stinger
9. **Gemini** - The Twins, two stick figures side by side
10. **Sagittarius** - The Archer/Teapot near the galactic center
11. **Capricornus** - Sea Goat, triangular shape
12. **Andromeda** - Princess, line of stars pointing to Andromeda Galaxy

## 🎨 Visual Features

### Grid Display
```
    N
    ↑
    00000000001111111111222222222233333333334444444444555555555566666666667777777777
    01234567890123456789012345678901234567890123456789012345678901234567890123456789
    ┌──────────────────────────────────────────────────────────────────────────────┐
 0 │................................................................................│
 1 │................................................................................│
 2 │................................................................................│
    ... (grid continues) ...
29 │................................................................................│
    └──────────────────────────────────────────────────────────────────────────────┘
    ↓
    S
    W                                                                              E
```

### Symbols Used
- `*` - Primary stars (brightest/most important)
- `+` - Secondary stars (fainter/supporting)
- `-` - Horizontal connections
- `|` - Vertical connections
- `/` `\` - Diagonal connections
- `.` - Background (faint stars/empty space)

## 🔧 Technical Implementation

### Bresenham's Line Algorithm
The program uses Bresenham's line algorithm to draw smooth connections between stars:
```c
void draw_line(int x1, int y1, int x2, int y2, char symbol) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    // ... implementation continues
}
```

### Smart Line Character Selection
Lines automatically use appropriate characters based on slope:
- Horizontal lines: `-`
- Vertical lines: `|`
- Diagonal lines: `/` or `\`

### Memory Efficiency
- All constellation data stored in static arrays (compile-time)
- No dynamic memory allocation
- Minimal memory footprint

## 🎯 Learning Outcomes

This project demonstrates:
- **Structures and Arrays**: Efficient data organization for stars and lines
- **Algorithm Implementation**: Bresenham's line drawing algorithm
- **Coordinate Systems**: 2D grid manipulation and bounds checking
- **Modular Design**: Clean separation between data, logic, and display
- **User Interface**: Terminal-based interactive menu
- **ASCII Art**: Creating visual patterns with text characters

## 📝 Future Enhancements

Potential improvements include:
- [ ] Animated star twinkling effects
- [ ] Constellation mythology information display
- [ ] Seasonal sky rotation simulation
- [ ] Custom constellation creator
- [ ] Color support for terminals
- [ ] Zoom and pan functionality
- [ ] Real-time star position calculation
- [ ] Save/Load constellation patterns

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Adding New Constellations
To add a new constellation:
1. Add star coordinates in `constellation.c`
2. Define connecting lines between stars
3. Add to the constellations array
4. Update the constellation count

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- Inspired by ancient astronomy and modern planetariums
- Bresenham's line algorithm for smooth connections
- The 88 modern constellations defined by the International Astronomical Union
- All star gazers and astronomers who mapped the night sky

## 🌟 Star the Project!

If you find this project interesting, please give it a star! It helps others discover the project and shows your appreciation for the work.

---

*"We are all in the gutter, but some of us are looking at the stars."* - Oscar Wilde

**Happy Stargazing!** ✨🔭
