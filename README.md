# Minesweeper Game in C++

A simple terminal-based implementation of the classic Minesweeper game using C++ and dynamic memory. The game randomly places mines on a grid and the user must reveal all safe plots without clicking on a mine.

## 🎮 Features

- Random mine placement
- Recursive reveal of adjacent safe plots
- User-friendly grid display
- Win and lose conditions
- Input validation
- Classic Minesweeper logic with numbers indicating nearby mines

## 🧠 How It Works

- The game begins by asking for grid size and number of mines.
- A hidden `mineMap` is generated with random mine placements (`-1` represents a mine).
- A `showingMap` is used to display the revealed tiles to the user (`'-'` represents unrevealed, `'0'` to `'8'` for adjacent mines, and `' '` for empty).
- Each turn, the user inputs a cell to reveal.
  - If the cell contains a mine: **Game Over**
  - If the cell is safe:
    - If it has 0 adjacent mines: recursively reveals surrounding cells.
    - Otherwise: shows the number of adjacent mines.

## 🛠️ How to Compile

```bash
g++ -o minesweeper minesweeper.cpp
./minesweeper
