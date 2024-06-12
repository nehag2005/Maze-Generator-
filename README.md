# Maze Generator Project

## Overview

This project is a maze generator written in C.

## Features

- Generates valid mazes with the following properties:
  - Single starting point `S`
  - Single exit point `E`
  - Contains only the characters: spaces (` `), walls (`#`), newline (`\n`), start (`S`), and exit (`E`)
  - Consistent row length
  - Consistent column height
  - Maximum dimensions: 100x100
  - Minimum dimensions: 5x5
  - No requirement for every row and column to start or end with a `#`
  - May include a trailing newline (`\n`) at the end of the file

## Implementation Details

### Algorithms

- **Depth-First Search (DFS)**: Utilized to explore all possible paths from the starting point `S`.
- **Backtracking**: Used to ensure that dead ends are handled correctly, allowing the algorithm to find a path from `S` to `E`.

### Data Structures
- **Stack Data Structure**: A stack is used to manage the backtracking process during the maze generation.

## Documentation

For more detailed documentation, please refer to the [Project Documentation](https://docs.google.com/document/d/1vSy_cT5sfX9b-wTjJ7euRMIcQSPR82tb/edit?usp=sharing&ouid=101277878034820580425&rtpof=true&sd=true).
