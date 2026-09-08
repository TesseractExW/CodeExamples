import collections


class Solution:
    # fmt: off
    def canReach(self, 
                 graph: list[list[tuple[int, int]]], 
                 fuel : list[int], 
                 order: list[int], 
                 capacity: int) -> bool:
    # fmt: on
        dp = [-1] * len(order)
        dp[0] = 0;

        for u in order:
            if dp[u] < 0:
                continue
            dp[u] = min(dp[u] + fuel[u], capacity)
            for v, dist in graph[u]:
                if dp[u] >= dist:
                    dp[v] = max(dp[v], dp[u] - dist)
        return dp[-1] >= 0

    # fmt: off
    def getOrder(
            self, 
            graph: list[list[tuple[int, int]]], 
            indeg: list[int]) -> list[int]:
        # fmt: on
        queue = collections.deque()
        order = []

        for i in range(len(graph)):
            if indeg[i] == 0:
                queue.append(i)
        while queue:
            u = queue.popleft()
            order.append(u)

            for v, dist in graph[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    queue.append(v)
        return order

    def minimumTankCapacity(self, n: int, edges: list[list[int]], fuel: list[int]) -> int:
        indeg = [0] * n
        graph = [[] for _ in range(n)]

        for u, v, dist in edges:
            graph[u].append((v, dist))
            indeg[v] += 1

        order = self.getOrder(graph, indeg)

        low = 0
        high = int(1e11)

        while low < high:
            mid = low + (high - low) // 2
            if self.canReach(graph, fuel, order, mid):
                high = mid
            else:
                low = mid + 1
        return low if self.canReach(graph, fuel, order, low) else -1
