# Merge Game

## Problem Statement

You are managing a system of `n` elements (0-indexed from `0` to `n - 1`). Initially, each element is in its own isolated component of size `1`.

You need to process a sequence of `queries` of three possible types:

1. **Type 0 (`[0]`):** Query the root node of the component with the **maximum size**. If there is a tie between multiple components with the maximum size, return the root with the **smallest node index**.
2. **Type 1 (`[1, u, v]`):** Merge the components containing nodes `u` and `v`. If `u` and `v` are already in the same component, no merge occurs.
3. **Type 2 (`[2]`):** Undo (roll back) the most recent successful `Type 1` merge operation.

Return an array of integers containing the answers to all `Type 0` queries in the order they appear.

---

## Examples

### Example 1
- **Input:** 
  - `n = 4`
  - `queries = [[0], [1, 1, 2], [0], [1, 0, 3], [1, 0, 1], [0], [2], [0]]`
- **Output:** `[0, 1, 0, 0]`
- **Explanation:**
  - Initial state: components `{0}, {1}, {2}, {3}`, all size `1`. The default max root (smallest index) is `0`.
  - **Query `[0]`:** Max size is `1`. Roots are `0, 1, 2, 3`. Smallest root is `0`. Output `0`.
  - **Query `[1, 1, 2]`:** Merge component `1` and `2`. Component `{1, 2}` has root `1` and size `2`.
  - **Query `[0]`:** Max size is `2` (root `1`). Output `1`.
  - **Query `[1, 0, 3]`:** Merge component `0` and `3`. Component `{0, 3}` has root `0` and size `2`.
  - **Query `[1, 0, 1]`:** Merge component `0` and `1`. Component `{0, 1, 2, 3}` has root `0` and size `4`.
  - **Query `[0]`:** Max size is `4` (root `0`). Output `0`.
  - **Query `[2]`:** Roll back the merge of component `0` and `1`. Component sizes revert to `{0, 3}` (size `2`) and `{1, 2}` (size `2`).
  - **Query `[0]`:** Tie between root `0` (size `2`) and root `1` (size `2`). Smallest index is `0`. Output `0`.

### Example 2
- **Input:** 
  - `n = 3`
  - `queries = [[1, 0, 1], [1, 1, 2], [0], [2], [0]]`
- **Output:** `[0, 0]`
- **Explanation:**
  - **Query `[1, 0, 1]`:** Merge `0` and `1`. Component `{0, 1}` has root `0` (size `2`).
  - **Query `[1, 1, 2]`:** Merge `1` and `2`. Component `{0, 1, 2}` has root `0` (size `3`).
  - **Query `[0]`:** Output `0`.
  - **Query `[2]`:** Undo last merge (`1` and `2`). Component `{0, 1}` remains (size `2`).
  - **Query `[0]`:** Output `0`.

---

## Constraints

- `1 <= n <= 10^5`
- `1 <= queries.length <= 10^5`
- `0 <= u, v < n`
- `queries[i]` is either `[0]`, `[1, u, v]`, or `[2]`.
- A `Type 2` query will only appear when there is at least one active successful `Type 1` merge operation to undo.
