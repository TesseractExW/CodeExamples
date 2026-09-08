#include <algorithm>
#include <vector>

class Solution {
public:
    int trappingRainWater(std::vector<int> &heights) {
        int left = 0;
        int right = (int)heights.size() - 1;

        int left_max = 0;
        int right_max = 0;
        int totalWater = 0;

        while (left < right) {
            if (heights[left] < heights[right]) {
                left_max = std::max(left_max, heights[left]);
                totalWater += left_max - heights[left];
                ++left;
            } else {
                right_max = std::max(right_max, heights[right]);
                totalWater += right_max - heights[right];
                --right;
            }
        }
        return totalWater;
    }
};
