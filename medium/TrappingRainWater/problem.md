# Trapping Rain Water

## Problem Statement

Given an array of non-negative integers `height` representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

## Examples

### Example 1

* **Input:** `height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]`
* **Output:** `6`
* **Explanation:**
  * Water is trapped between elevation peaks.
  * The total units of trapped rain water equals `6`.

### Example 2

* **Input:** `height = [4, 2, 0, 3, 2, 5]`
* **Output:** `9`
* **Explanation:**
  * Trapped water at each index: `[0, 2, 4, 1, 2, 0]`.
  * Total trapped water = `0 + 2 + 4 + 1 + 2 + 0 = 9`.
