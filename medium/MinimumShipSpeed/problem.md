# Minimum Ship Speed

## Problem Statement

Given an array of positive integers `distances` representing the distance of each delivery item in **meters** (`m`), and an integer `target` representing the total maximum hours available, find the **minimum positive integer speed** in kilometers per hour (`km/h`) required to deliver all items within `target` hours.

Each item must be delivered individually in the order given. Because shipments operate on strict hourly scheduling, the delivery time for each item is rounded **up** to the nearest whole hour. That is, if a delivery takes a fractional amount of time, the ship must wait until the next integer hour before starting the next delivery.

If it is impossible to deliver all items within `target` hours regardless of how fast the ship travels, return `-1`.

---

## Examples

### Example 1
- **Input:** `distances = [1000, 3000, 2000]`, `target = 6`
- **Output:** `1`
- **Explanation:** 
  - Convert distances to kilometers (`km`): `[1, 3, 2]`.
  - Testing speed `S = 1 km/h`:
    - Item 1 (`1 km`): `1 / 1 = 1 hour`
    - Item 2 (`3 km`): `3 / 1 = 3 hours`
    - Item 3 (`2 km`): `2 / 1 = 2 hours`
    - **Total Time:** `1 + 3 + 2 = 6 hours` (<= `6` target).
  - The minimum speed required is `1`.

### Example 2
- **Input:** `distances = [3000, 5000, 4000]`, `target = 6`
- **Output:** `3`
- **Explanation:** 
  - Convert distances to kilometers (`km`): `[3, 5, 4]`.
  - Speed `S = 2 km/h`:
    - Total Time = `ceiling(3/2) + ceiling(5/2) + ceiling(4/2) = 2 + 3 + 2 = 7 hours` (> `6`, too slow).
  - Speed `S = 3 km/h`:
    - Total Time = `ceiling(3/3) + ceiling(5/3) + ceiling(4/3) = 1 + 2 + 2 = 5 hours` (<= `6`).
  - The minimum speed required is `3`.

### Example 3
- **Input:** `distances = [1000, 2000, 3000]`, `target = 2`
- **Output:** `-1`
- **Explanation:** 
  - There are `3` items to deliver. Since each item takes at least `1 hour`, the absolute minimum time needed to deliver all items is `3 hours`.
  - It is impossible to complete `3` deliveries in `2 hours`, so the function returns `-1`.

