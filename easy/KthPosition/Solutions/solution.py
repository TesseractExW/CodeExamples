class Solution:
    def kthPosition(self, pos: list[int], queries: list[list[int]]):
        logJump = 32

        jumps = [[0] * logJump for _ in range(len(pos))]
        for i in range(len(jumps)):
            jumps[i][0] = pos[i]
        for j in range(1, logJump):
            for i in range(len(jumps)):
                jumps[i][j] = jumps[jumps[i][j - 1]][j - 1]

        results = [0] * len(queries)
        for i in range(len(queries)):
            start = queries[i][0]
            totalJump = queries[i][1]

            for j in range(logJump):
                if (totalJump >> j) & 1:
                    start = jumps[start][j]
            results[i] = start
        return results
