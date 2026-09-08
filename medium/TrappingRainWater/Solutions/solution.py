class Solution:
    def trappingRainWater(self, heights: list[int]) -> int:
        left = 0
        right = len(heights) - 1

        left_max = 0
        right_max = 0
        totalWater = 0

        while left < right:
            if heights[left] < heights[right]:
                left_max = max(left_max, heights[left])
                totalWater += left_max - heights[left]
                left += 1
            else:
                right_max = max(right_max, heights[right])
                totalWater += right_max - heights[right]
                right -= 1
        return totalWater
