class Solution:
    def longestPathOnAGrid(self, grid: list[list[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        answer = 0
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m):
            for j in range(n):
                dp[i + 1][j + 1] = grid[i][j] * (max(dp[i][j + 1], dp[i + 1][j]) + 1)
                answer = max(answer, dp[i + 1][j + 1])
        return answer
