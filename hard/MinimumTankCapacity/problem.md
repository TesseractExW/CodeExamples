# Minimum Tank Capacity

## Problem Statement

You are given a Directed Acyclic Graph (DAG) representing a network of one-way roads connecting `n` stations numbered from `0` to `n - 1`. You want to find the minimum fuel tank capacity required to travel from starting station `0` to destination station `n - 1`.

You are given:
* `n`: The total number of stations (`0` to `n - 1`).
* `edges`: A 2D array where each element `[u, v, dist]` represents a one-way road from station `u` to station `v` of length `dist`.
* `fuel`: An array of size `n`, where `fuel[i]` is the amount of fuel available to pick up at station `i`.

### Rules:
1. Traveling `1` unit of distance consumes `1` unit of fuel.
2. You start at station `0` with a full fuel tank of capacity `C`.
3. Upon arriving at any station `i` (including station `0`), you automatically refuel by `fuel[i]` units, but your current fuel can **never exceed** the maximum tank capacity `C`.
4. If your fuel drops below `0` at any point during travel along a road, you cannot complete that transition.

Return the **minimum integer fuel capacity `C`** required to reach station `n - 1` from station `0`. If station `n - 1` is unreachable regardless of how large `C` is, return `-1`.

## Examples

### Example 1

* **Input:** 
  * `n = 3`
  * `edges = [[0, 1, 5], [1, 2, 5]]`
  * `fuel = [0, 3, 0]`

* **Output:** `7`

* **Explanation:**
  * **Testing Capacity `C = 6`:**
    * Start at `0` with `6` fuel.
    * Travel to `1` (cost `5`): remaining fuel = `1`.
    * Refuel at `1` (`+3`): new fuel = `min(6, 1 + 3) = 4`.
    * Travel to `2` requires `5` fuel, but we only have `4`. Cannot reach `2`.
  * **Testing Capacity `C = 7`:**
    * Start at `0` with `7` fuel.
    * Travel to `1` (cost `5`): remaining fuel = `2`.
    * Refuel at `1` (`+3`): new fuel = `min(7, 2 + 3) = 5`.
    * Travel to `2` (cost `5`): remaining fuel = `0`. Reached `2`!
  * Minimum capacity required is `7`.

### Example 2

* **Input:**
  * `n = 4`
  * `edges = [[0, 1, 4], [0, 2, 8], [1, 3, 6], [2, 3, 3]]`
  * `fuel = [0, 2, 1, 0]`

* **Output:** `9`

* **Explanation:**
  * Path `0 -> 1 -> 3`: Total distance `4 + 6 = 10`. With `fuel[1] = 2`, capacity `9` allows `0 -> 1` (rem. `5`), refuel to `7`, then `1 -> 3` (cost `6`, rem. `1`).
  * Path `0 -> 2 -> 3`: Total distance `8 + 3 = 11`. Capacity `9` does not allow `0 -> 2` directly.
  * Minimum valid capacity across all paths to reach `3` is `9`.

### Example 3

* **Input:**
  * `n = 3`
  * `edges = [[0, 1, 10]]`
  * `fuel = [0, 0, 0]`

* **Output:** `-1`

* **Explanation:**
  * There are no edges leading to station `2`. Destination `n - 1` is completely disconnected.
  * Return `-1`.

## Constraints

* `2 <= n <= 10^4`
* `1 <= edges.length <= 5 * 10^4`
* `edges[i] = [u, v, dist]` where `0 <= u, v < n` and `1 <= dist <= 10^6`
* `0 <= fuel[i] <= 10^6`
* The graph is guaranteed to be a **Directed Acyclic Graph (DAG)**.
