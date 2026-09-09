#include <vector>

class Solution {
public:
    // clang-format off
    std::vector<int> kthPosition(
        std::vector<int> &pos,
        std::vector<std::vector<int>> &queries)
    {
        // clang-format on
        const int logJump = 32;
        // clang-format skip
        std::vector<std::vector<int>> jumps(pos.size(), std::vector<int>(logJump));
        std::vector<int> results(queries.size());

        for (int i = 0; i < (int)jumps.size(); ++i)
            jumps[i][0] = pos[i];
        for (int j = 1; j < logJump; ++j) {
            for (int i = 0; i < (int)jumps.size(); ++i) {
                jumps[i][j] = jumps[jumps[i][j - 1]][j - 1];
            }
        }

        for (int i = 0; i < queries.size(); ++i) {
            int start = queries[i][0];
            int totalJump = queries[i][1];

            for (int j = 0; j < logJump; ++j) {
                if ((totalJump >> j) & 1)
                    start = jumps[start][j];
            }
            results[i] = start;
        }
        return results;
    }
};
