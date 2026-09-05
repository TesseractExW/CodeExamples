# Longest path on a grid

## Problem Statement

Given an `m x n` binary matrix `grid`, where `0` represents an open cell and `1` represents a wall (an impassable cell), return the maximum length (number of cells) of a valid path consisting only of open cells (`0`).

From any open cell `(r, c)`, you can only move in two directions: **down** to `(r + 1, c)` or **right** to `(r, c + 1)`. You cannot move diagonally, left, up, outside the grid boundary, or onto a cell containing a wall (`1`).

You may **start the path at any open cell (`0`)** in the grid. If the grid contains no open cells, return `0`.

---

## Examples

### Example 1
- **Input:** `grid = [[0, 0, 1], [1, 0, 0], [0, 0, 0]]`
- **Output:** `5`
- **Explanation:** 
  - Visualizing the grid:
    ```
    0 -> 0    1
         |
    1    0 -> 0
              |
    0    0    0
    ```
  - Starting at `(0, 0)`:
    - Move right to `(0, 1)`
    - Move down to `(1, 1)`
    - Move right to `(1, 2)`
    - Move down to `(2, 2)`
  - All 5 visited cells are `0`s, giving a maximum path length of `5`.

### Example 2
- **Input:** `grid = [[1, 0], [0, 1]]`
- **Output:** `1`
- **Explanation:** 
  - Visualizing the grid:
    ```
    1    0
    0    1
    ```
  - Starting at `(0, 1)` (value `0`), moving down leads to `(1, 1)` (value `1`, a wall).
  - Starting at `(1, 0)` (value `0`), moving right leads to `(1, 1)` (value `1`, a wall).
  - The longest valid path consists of a single open cell, so the output is `1`.

### Example 3
- **Input:** `grid = [[1, 1], [1, 1]]`
- **Output:** `0`
- **Explanation:** 
  - Every cell in the grid is a wall (`1`). No path can be formed, so the output is `0`.
