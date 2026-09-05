# Two Sum Problem

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the 0-based **indices** of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 3]`, `target = 5`
- **Output:** `[1, 2]`
- **Explanation:** 
  - `nums[1]` is `2`
  - `nums[2]` is `3`
  - `2 + 3 = 5`, which equals the `target`. Therefore, the indices are `1` and `2`.

### Example 2
- **Input:** `nums = [2, 7, 11, 15]`, `target = 9`
- **Output:** `[0, 1]`
- **Explanation:** 
  - `nums[0] + nums[1] = 2 + 7 = 9`
  - The elements at indices `0` and `1` add up to `9`.
