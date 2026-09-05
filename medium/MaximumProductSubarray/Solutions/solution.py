class Solution:
    def maximumProductSubarray(self, nums: list[int]) -> int:
        minSoFar = 1
        maxSoFar = 1
        answer = 0

        for num in nums:
            temp = minSoFar
            minSoFar = min(num, minSoFar * num, maxSoFar * num)
            maxSoFar = max(num, maxSoFar * num, temp * num)
            answer = max(answer, maxSoFar)
        return answer
