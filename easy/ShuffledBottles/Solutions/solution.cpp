#include <vector>

class Solution {
private:
    virtual int count(const std::vector<int> &bottles, int i);

public:
    void shuffledBottles(std::vector<int> &bottles) {
        for (int i = 0; i < (int)bottles.size(); ++i) {
            int j = i;
            while (count(bottles, i) < i) {
                std::swap(bottles[i], bottles[++j]);
            }
        }
    }
};
