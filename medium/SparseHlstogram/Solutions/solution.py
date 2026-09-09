import bisect


class Solution:
    def sparseHistogram(self, points: list[list[int]], queries: list[list[int]]) -> list[int]:
        points.sort()

        n = len(points)
        x = [0] * n
        prefix = [0] * (n + 1)
        answer = [0] * len(queries)

        for i in range(n):
            x[i] = points[i][0]
            prefix[i + 1] = prefix[i] + points[i][1]

        for i, query in enumerate(queries):
            left = bisect.bisect_left(x, query[0])
            right = bisect.bisect_right(x, query[1])
            answer[i] = prefix[right] - prefix[left]
        return answer
