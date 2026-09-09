#include <vector>

class Solution {
public:
    int trappingRainWater(std::vector<int> &heights) {
        int n = (int)heights.size();
        int totalWater = 0;

        std::vector<int> left_max(n, heights[0]);
        std::vector<int> right_max(n, heights[n - 1]);

        for (int i = 1; i < n; ++i)
            left_max[i] = std::max(left_max[i - 1], heights[i]);
        for (int i = n - 2; i >= 0; --i)
            right_max[i] = std::max(right_max[i + 1], heights[i]);

        for (int i = 0; i < n; ++i)
            totalWater += std::min(left_max[i], right_max[i]) - heights[i];
        return totalWater;
    }
};
