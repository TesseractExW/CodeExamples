from collections import deque


class Solution:
    def specialQueue(self, P: list[bool], C: list[int]) -> list[int]:
        specialCount = 0
        dq = deque()

        for p, c in zip(P, C):
            specialCount += int(p)
            if specialCount & 1:
                dq.append(c)
            else:
                dq.appendleft(c)
        return list(dq)
