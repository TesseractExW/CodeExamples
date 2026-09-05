# Valid Parentheses Substring Problem

## Problem Statement

Given a string $s$ consisting only of the characters `'('`, `')'`, `'['`, `']'`, `'{'`, and `'}'`, determine whether there exists **at least one non-empty substring** that forms a valid set of matched and correctly nested parentheses.

---

## Examples

### Example 1
- **Input:** `s = "())"`
- **Output:** `True`
- **Explanation:** 
  The substring from index `0` to `1` is `"()"`. 
  - `'('` correctly pairs with `')'`.
  - Since `"()"` is a non-empty valid substring, the result is `True`.

### Example 2
- **Input:** `s = "[(}]"`
- **Output:** `False`
- **Explanation:** 
  Let's inspect all possible non-empty contiguous substrings:
  - `"["`, `"("`, `"}"`, `"]"` — Single characters are incomplete/invalid.
  - `"[( "` — Unmatched types.
  - `"(}"` — Mismatched bracket types (`(` does not close with `}`).
  - `"}]"` — Closing brackets without open brackets.
  - `"[(}"` — Mismatched sequence.
  - `"(}]"` — Mismatched sequence.
  - `"[(}]"` — Intersecting/crossed brackets (`(` is closed after `}` starts).
  
  None of the contiguous substrings form a valid pattern, so the result is `False`.

### Example 3
- **Input:** `s = "}{[()]}("`
- **Output:** `True`
- **Explanation:** 
  Although the entire string starting with `}` and ending with `(` is invalid, there exists an embedded non-empty substring at index `2` to `7`: **`"[()]"`**.
  - `()` forms a valid inner pair.
  - `[]` correctly encloses `()`.
  
  Therefore, a valid non-empty substring exists, and the output is `True`.
