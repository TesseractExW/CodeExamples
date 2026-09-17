from abc import abstractmethod


class Solution:
    @abstractmethod
    def count(self, bottles: list[int], i: int) -> int:
        pass

    def shuffledBottles(self, bottles: list[int]) -> None:
        for i in range(len(bottles)):
            j = i
            while self.count(bottles, i) < i:
                j += 1
                bottles[i], bottles[j] = bottles[j], bottles[i]
