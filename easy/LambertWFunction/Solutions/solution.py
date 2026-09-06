class Solution:
    def lambertWFunction(self, y: float) -> float:
        low = 0.0
        high = 100.0

        while high - low < high * 1e-9:
            mid = low + (high - low) / 2
            if mid**mid <= y:
                low = mid
            else:
                high = mid
        return low
