class Solution:
    def canDelivery(self, distances: list[int], target: int, speed: int) -> bool:
        totalTime = 0

        for distance in distances:
            totalTime += (distance // 1000) // speed
            if totalTime > target:
                return False
        return True

    def minimumShipSpeed(self, distances: list[int], target: int) -> int:
        low = 1
        high = int(1e9)

        while low < high:
            mid = low + (high - low) // 2
            if self.canDelivery(distances, target, mid):
                high = mid
            else:
                low = mid + 1
        return low if self.canDelivery(distances, target, low) else -1
