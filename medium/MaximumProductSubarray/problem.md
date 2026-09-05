# Maximum Product Subarray

## Problem Statement

Given an integer array `nums`, find a contiguous subarray (can be empty) that has the largest product, and return **the maximum product**.

A **subarray** is a contiguous sequence of elements within an array.

The test cases are generated such that the answer will fit in a **32-bit integer**.

---

## Examples

### Example 1
- **Input:** `nums = [2, 3, -2, 4]`
- **Output:** `6`
- **Explanation:** 
  - Subarray `[2, 3]` has the maximum product `2 * 3 = 6`.
  - Adding `-2` to the path yields `2 * 3 * (-2) = -12`.
  - The single element `4` gives `4`, which is less than `6`.

### Example 2
- **Input:** `nums = [-2, 1]`
- **Output:** `0`
- **Explanation:** 
  - The maximum product is `0`.
  - Empty subarray is also a valid choice.

### Example 3
- **Input:** `nums = [-2, 3, -4]`
- **Output:** `24`
- **Explanation:** 
  - The entire array `[-2, 3, -4]` forms a continuous subarray.
  - Multiplying two negative numbers produces a positive result: `(-2) * 3 * (-4) = 24`.
