class Solution:
    def trappingRainWater(self, heights: list[int]) -> int:
        n = len(heights)
        totalWater = 0

        left_max = [heights[0]] * n
        right_max = [heights[-1]] * n

        for i in range(1, n):
            left_max[i] = max(left_max[i - 1], heights[i])
        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], heights[i])

        for i in range(n):
            totalWater += min(left_max[i], right_max[i]) - heights[i]
        return totalWater
