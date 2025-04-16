# So Long

![Game Banner](https://img.shields.io/badge/So%20Long-2D%20Game-blue)
![Language](https://img.shields.io/badge/Language-C-green)
![Graphics](https://img.shields.io/badge/Graphics-MiniLibX-orange)
![Score](https://img.shields.io/badge/1337%20Project-Completed-success)

## 📖 Description

"So Long" is a simple 2D adventure game where the player must collect all items (coins) on the map before exiting through the designated exit door. The game utilizes the MiniLibX graphics library to create a smooth and visually appealing experience.


## 🎮 Game Features

- **Player Movement**: Navigate through the map using the WASD keys or arrow keys
- **Collectibles**: Gather all coins before heading to the exit
- **Movement Counter**: Tracks and displays the number of moves
- **Clean Exit**: ESC key or clicking the window's X button closes the game properly

## 🗺️ Map System

Maps are defined in `.ber` files with the following components:

- `1`: Wall - Blocks player movement
- `0`: Empty space - Player can move here
- `P`: Player starting position (only one allowed)
- `E`: Exit - The goal location (only one allowed)
- `C`: Collectibles (coins) - Must collect all before exiting

Example of a valid map:
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

## 📁 Project Structure

```
.
├── Makefile
├── header.h                # Main header file with structures and function prototypes
├── so_long.c               # Main program file
├── libft                   # Custom library with utility functions
│   ├── ft_itoa.c
│   ├── ft_split.c
│   ├── ft_strlen.c
│   ├── ft_swap.c
│   ├── ft_strjoin.c
│   ├── ft_strdup.c
│   └── ft_putstr.c
├── utils                   # Utility functions for the game
│   ├── move_player.c       # Player movement logic
│   ├── checks.c            # Map validation functions
│   ├── keys__textures.c    # Key handling and texture loading
│   └── utils.c             # General utility functions
├── maps                    # Map files for the game
│   ├── map.ber
│   └── map2.ber
└── textures                # Game textures in XPM format
    ├── pngegg.xpm          # Player texture
    ├── pngegg_1_.xpm       # Collectible texture
    ├── wall_1_.xpm         # Wall texture
    ├── exit.xpm            # Exit texture
    ├── exit1.xpm           # Alternative exit texture
    └── floor1_1_.xpm       # Floor texture
```

## 🛠️ Installation and Usage

### Requirements

- GCC compiler
- MiniLibX library
- macOS (the project is designed for macOS with its specific graphics frameworks)

### Compilation

```bash
make
```

This will compile the program and create the executable `so_long`.

### Running the Game

```bash
./so_long maps/map.ber
```

Replace `maps/map.ber` with the path to any valid map file.

## 🎮 Game Controls

- `W` or `↑`: Move up
- `A` or `←`: Move left
- `S` or `↓`: Move down
- `D` or `→`: Move right
- `ESC`: Quit the game

## 📋 Game Rules

1. The player must collect all coins on the map
2. After collecting all coins, the player can exit through the door (E)
3. The game tracks and displays the number of movements
4. The player cannot walk through walls
5. The game is won when the player reaches the exit after collecting all coins

## 🔍 Map Validation

The program checks for the following requirements in map files:
- Maps must be rectangular
- Maps must be enclosed by walls
- Maps must contain exactly 1 player starting position (P)
- Maps must contain exactly 1 exit (E)
- Maps must contain at least 1 collectible (C)
- There must be a valid path to collect all coins and reach the exit

## 💻 Technical Implementation

The game utilizes the MiniLibX library for:
- Window management
- Image rendering
- Key event handling

The core game logic implements:
- Path finding to validate maps
- Movement tracking and collision detection
- Game state management

## 👨‍💻 Author

- [yoelansa](https://github.com/UN-35)

## 📜 License

This project is part of the 1337 School curriculum and is licensed under the [1337 License](https://1337.ma/).

---

*"So long, and thanks for all the fish!" - Douglas Adams*
