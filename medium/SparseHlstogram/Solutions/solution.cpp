#include <algorithm>
#include <vector>

class Solution {
public:
    // clang-format off
    std::vector<long long> sparseHistogram(
        std::vector<std::vector<int>> &points, 
        std::vector<std::vector<int>> &queries) 
    {
        // clang-format on
        std::ranges::sort(points);

        int n = points.size();
        std::vector<int> x(n);
        std::vector<long long> prefix(n + 1, 0);
        std::vector<long long> answer(queries.size());

        for (int i = 0; i < n; ++i) {
            x[i] = points[i][0];
            prefix[i + 1] = prefix[i] + points[i][1];
        }

        for (int i = 0; i < queries.size(); ++i) {
            // clang-format off
            int left  = std::lower_bound(x.begin(), x.end(), queries[i][0]) - x.begin();
            int right = std::upper_bound(x.begin(), x.end(), queries[i][1]) - x.begin();
            answer[i] = prefix[right] - prefix[left];
            // clang-format on
        }
        return answer;
    }
};
