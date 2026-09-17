#include <cmath>

class Solution {
public:
    long double lambertWFunction(long double y) {
        long double low = 0;
        long double high = 100;

        while (high - low > high * 1e-9l) {
            long double mid = low + (high - low) / 2;
            if (std::pow(mid, mid) <= y) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
