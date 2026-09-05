#include <algorithm>
#include <vector>

class Solution {
public:
    int maximumProductSubarray(std::vector<int> &nums) {
        int maxSoFar = 1;
        int minSoFar = 1;
        int answer = 0;

        for (int num : nums) {
            int temp = minSoFar;
            minSoFar = std::min({num, minSoFar * num, maxSoFar * num});
            maxSoFar = std::max({num, maxSoFar * num, temp * num});
            answer = std::max(answer, maxSoFar);
        }
        return answer;
    }
};
