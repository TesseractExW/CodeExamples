#include <deque>
#include <vector>

class Solution {
public:
    std::vector<int> specialQueue(std::vector<bool> &P, std::vector<int> &C) {
        int specialCount = 0;
        std::deque<int> dq;

        for (int i = 0; i < (int)P.size(); ++i) {
            specialCount += (int)P[i];
            if (specialCount & 1) {
                dq.push_back(C[i]);
            } else {
                dq.push_front(C[i]);
            }
        }
        return std::vector<int>(dq.begin(), dq.end());
    }
};
