# Kth Position Problem

## Problem Statement

Given an array `pos` of size N representing the next position index you move to from each index `i` (i.e., `i -> pos[i]`), answer Q queries where each query is represented as `Q[i] = [start_node, total_jumps]`.

For each query `Q[i]`, determine the final position you end up at if you start at index `Q[i][0]` and make `Q[i][1]` jumps.

---

## Examples

### Example 1
- **Input:** 
  - `pos = [0, 1, 2, 4, 3]`
  - `Q = [[0, 3], [4, 3]]`
- **Output:** `[0, 3]`
- **Explanation:** 
  - **Query `Q[0] = [0, 3]`:** Start at index `Q[0][0] = 0`, jump `Q[0][1] = 3` times.
    - 0 -> 0 -> 0 -> 0 (land at index 0).
  - **Query `Q[1] = [4, 3]`:** Start at index `Q[1][0] = 4`, jump `Q[1][1] = 3` times.
    - 4 -> 3 -> 4 -> 3 (land at index 3).
