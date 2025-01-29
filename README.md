# Minesweeper in C++

This is a simple implementation of the classic Minesweeper game written in C++. The game is played on an `n x n` grid containing hidden mines. The objective is to uncover all non-mine cells without triggering any mines.

## Features

- Random mine placement on the board.
- Numbered hints indicating the number of adjacent mines.
- Ability to uncover cells and avoid mines.
- Win condition when all non-mine cells are revealed.

## How to Compile and Run

You can compile the `minesweeper.cpp` file using a C++ compiler like `g++`:

```sh
 g++ -o minesweeper minesweeper.cpp
 ./minesweeper
```

## How to Play

1. When the game starts, a board of size `n x n` is generated with a set number of mines placed randomly.
2. You will be prompted to input a tile number.
3. If you uncover a mine, you lose the game.
4. If you uncover an empty cell, it will show a number indicating how many adjacent mines exist.
5. The game continues until all non-mine cells are revealed, at which point you win.

## Controls

- Input a tile number.
- Avoid stepping on mines!

## Notes

- The board size (`n`) and number of mines can be adjusted in the source code.
- This implementation may require further enhancements like flagging suspected mines and better UI representation.

Enjoy playing Minesweeper!
