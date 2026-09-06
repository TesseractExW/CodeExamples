# Lambert W Function

## Problem Statement

Given a positive floating-point number `y` where `y >= 1.0`, find the value of `x` such that:

`x^x = y`

You are guaranteed that `x` is in the range `[1.0, 100.0]` and `y` is in the range `[1.0, 1.0 * 10 ^ 200]`. Because `f(x) = x^x` is strictly increasing for `x >= 1.0`, there exists exactly one unique real solution `x` for any valid `y`.

Your output will be accepted if the absolute or relative error between your answer and the actual answer is strictly less than `10^-6` (`10e-6`):

`Error < 10^-6`

---

## Examples

### Example 1

* **Input:** `y = 27.0`
* **Output:** `3.000000`
* **Explanation:** 
  * `3.0^3.0 = 27.0`, which equals `y`.

### Example 2

* **Input:** `y = 1.0`
* **Output:** `1.000000`
* **Explanation:** 
  * `1.0^1.0 = 1.0`, which equals `y`.

### Example 3

* **Input:** `y = 4.0`
* **Output:** `2.000000`
* **Explanation:** 
  * `2.0^2.0 = 4.0`, which equals `y`.

### Example 4

* **Input:** `y = 2.0`
* **Output:** `1.559610`
* **Explanation:** 
  * `1.559610^1.559610` is approximately `2.000000`, which is accurate to within `< 10^-6`.
