# Sparse Histogram

## Problem Statement

Given a sparse histogram represented as an array of 2D points `points` where `points[i] = [X_i, Y_i]` (`X_i` represents the bin location and `Y_i` represents the height or frequency at `X_i`), and an array of `queries` where `queries[j] = [begin, end]` (inclusive range).

Return an array of answers where `ans[j]` is the total sum of `Y_i` for all histogram points whose position `X_i` satisfies `begin <= X_i <= end`.

If no points fall within the range `[begin, end]`, the answer for that query is `0`.

---

## Examples

### Example 1

* **Input:**
  * `points = [[1, 5], [4, 10], [7, 3], [10, 2]]`
  * `queries = [[1, 5], [2, 8], [11, 15]]`

* **Output:** `[15, 13, 0]`

* **Explanation:**
  * **Query 1 `[1, 5]`:** Points at `X = 1` (`Y = 5`) and `X = 4` (`Y = 10`) fall in range. Total sum = `5 + 10 = 15`.
  * **Query 2 `[2, 8]`:** Points at `X = 4` (`Y = 10`) and `X = 7` (`Y = 3`) fall in range. Total sum = `10 + 3 = 13`.
  * **Query 3 `[11, 15]`:** No points have `X` in range `[11, 15]`. Total sum = `0`.

### Example 2

* **Input:**
  * `points = [[-5, 8], [0, 4], [3, 12]]`
  * `queries = [[-10, 5], [0, 0], [1, 2]]`

* **Output:** `[24, 4, 0]`

* **Explanation:**
  * **Query 1 `[-10, 5]`:** All points (`X = -5, 0, 3`) fall in range. Total sum = `8 + 4 + 12 = 24`.
  * **Query 2 `[0, 0]`:** Only the point at `X = 0` (`Y = 4`) falls in range. Total sum = `4`.
  * **Query 3 `[1, 2]`:** No points fall in range. Total sum = `0`.

---

## Constraints

* `1 <= points.length <= 10^5`
* `1 <= queries.length <= 10^5`
* `-10^9 <= X_i, begin, end <= 10^9`
* `0 <= Y_i <= 10^9`
* `begin <= end` for all queries.
