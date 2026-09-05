#include <algorithm>
#include <vector>

class Solution {
public:
    int longestPathOnAGrid(std::vector<std::vector<int>> &grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        int answer = 0;
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i + 1][j + 1] = grid[i][j] * (std::max(dp[i][j + 1], dp[i + 1][j]) + 1);
                answer = std::max(answer, dp[i + 1][j + 1]);
            }
        }
        return answer;
    }
};
