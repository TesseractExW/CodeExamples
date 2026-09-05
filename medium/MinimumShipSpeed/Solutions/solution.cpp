#include <vector>

class Solution {
private:
    bool canDeliver(const std::vector<int> &distances, int target, int speed) {
        long long totalTime = 0;

        for (int distance : distances) {
            totalTime += (distance / 1000LL) / speed;
            if (totalTime > target) {
                return false;
            }
        }
        return true;
    }

public:
    int minimumShipSpeed(std::vector<int> &distances, int target) {
        int low = 1;
        int high = (int)1e9;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canDeliver(distances, target, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return canDeliver(distances, target, low) ? low : -1;
    }
};
