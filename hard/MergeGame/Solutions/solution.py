from collections import deque


class Solution:
    def find(self, i: int) -> int:
        if self.parents[i] == i:
            return i
        else:
            return self.find(self.parents[i])

    def unite(self, i: int, j: int) -> bool:
        a = self.find(i)
        b = self.find(j)

        if a == b:
            return False
        elif self.sizes[a] < self.sizes[b]:
            return self.unite(b, a)

        self.parents[b] = a
        self.sizes[a] += self.sizes[b]

        self.unite_stack.append((a, b))

        curr_top = self.top_stack[-1]
        if (-self.sizes[a], a) < (-self.sizes[curr_top], curr_top):
            curr_top = a

        self.top_stack.append(curr_top)
        return True

    def pop(self) -> None:
        a, b = self.unite_stack.pop()
        self.top_stack.pop()

        self.parents[b] = b
        self.sizes[a] -= self.sizes[b]

    def __init__(self) -> None:
        self.parents = []
        self.sizes = []
        self.unite_stack = deque()
        self.top_stack = deque()

    def mergeGame(self, n: int, queries: list[list[int]]) -> list[int]:
        self.sizes = [1] * n
        self.parents = [i for i in range(n)]

        self.top_stack.append(0)

        answer = []
        for query in queries:
            if query[0] == 0:
                answer.append(self.top_stack[-1])
            elif query[0] == 1:
                self.unite(query[1], query[2])
            else:
                self.pop()
        return answer
