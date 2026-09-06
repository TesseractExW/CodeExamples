# Special Queue

## Problem Statement

You are hired as a roller coaster manager at an amusement park and tasked with building an automated queue management system. 

You are given two arrays of equal length:
1. `P`: A boolean array where `P[i]` is `true` if the `i`-th customer is a **special customer**, and `false` if they are a regular customer.
2. `C`: An integer array where `C[i]` represents the unique customer ID of the `i`-th customer.

Customers arrive one by one in the order they appear in the arrays (from index `0` to `N - 1`). The system maintains a running tally of the total number of special customers currently processed into the queue.

When customer `i` arrives:
- If `P[i]` is `true`, increment the total count of special customers by `1`.
- If the current total count of special customers is **even**, customer `i` is added to the **front** of the queue.
- If the current total count of special customers is **odd**, customer `i` is added to the **back** of the queue.

Return an array of customer IDs representing the final order of customers in the queue after all customers have entered.

---

## Examples

### Example 1

- **Input:** `P = [true, false, true, true]`, `C = [101, 102, 103, 104]`
- **Output:** `[103, 101, 102, 104]`
- **Explanation:**
  - **Initial State:** Queue = `[]`, Special Count = `0`
  - **Customer 0 (`C[0] = 101`, `P[0] = true`):**
    - Special count increases to `1` (odd).
    - `101` goes to the **back** of the queue.
    - Queue state: `[101]`
  - **Customer 1 (`C[1] = 102`, `P[1] = false`):**
    - Special count remains `1` (odd).
    - `102` goes to the **back** of the queue.
    - Queue state: `[101, 102]`
  - **Customer 2 (`C[2] = 103`, `P[2] = true`):**
    - Special count increases to `2` (even).
    - `103` goes to the **front** of the queue.
    - Queue state: `[103, 101, 102]`
  - **Customer 3 (`C[3] = 104`, `P[3] = true`):**
    - Special count increases to `3` (odd).
    - `104` goes to the **back** of the queue.
    - Queue state: `[103, 101, 102, 104]`

### Example 2

- **Input:** `P = [false, false, true, false]`, `C = [1, 2, 3, 4]`
- **Output:** `[2, 1, 3, 4]`
- **Explanation:**
  - **Customer 0 (`C[0] = 1`, `P[0] = false`):** Special count is `0` (even). Insert `1` at front -> `[1]`
  - **Customer 1 (`C[1] = 2`, `P[1] = false`):** Special count is `0` (even). Insert `2` at front -> `[2, 1]`
  - **Customer 2 (`C[2] = 3`, `P[2] = true`):** Special count increases to `1` (odd). Insert `3` at back -> `[2, 1, 3]`
  - **Customer 3 (`C[3] = 4`, `P[3] = false`):** Special count remains `1` (odd). Insert `4` at back -> `[2, 1, 3, 4]`

### Example 3

- **Input:** `P = [true, true]`, `C = [50, 60]`
- **Output:** `[60, 50]`
- **Explanation:**
  - **Customer 0 (`C[0] = 50`, `P[0] = true`):** Special count becomes `1` (odd). Insert `50` at back -> `[50]`
  - **Customer 1 (`C[1] = 60`, `P[1] = true`):** Special count becomes `2` (even). Insert `60` at front -> `[60, 50]`
