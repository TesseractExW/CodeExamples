# Shuffled Bottles

## Problem Statement

You are given an array `bottles` of integers representing a collection of bottles in a shuffled order. Your goal is to unshuffle the array so that all bottles are restored to their correct target order in-place.

You are provided with an abstract/virtual helper method:

`count(self, bottles: list[int], i: int) -> int`

When called, `count(bottles, i)` inspects the prefix of the array from index `0` to `i` (inclusive) and returns the total number of bottles in `bottles[0...i]` that are currently in their correct target positions.

Implement the method `shuffledBottles(self, bottles: list[int]) -> None` to unshuffle the bottles array in-place using calls to `count`.

---

## Examples

### Example 1

- **Input:** `bottles = [3, 1, 2]`
- **Target Order:** `[1, 2, 3]`
- **Output:** `[1, 2, 3]`

### Example 2

- **Input:** `bottles = [2, 1]`
- **Target Order:** `[1, 2]`
- **Output:** `[1, 2]`

---

## Constraints

- `1 <= bottles.length <= 1000`
- Each bottle ID in `bottles` is unique.
- `count(bottles, i)` returns an integer in the range `[0, i + 1]`.
- The array `bottles` must be modified **in-place** (`O(1)` extra space).
