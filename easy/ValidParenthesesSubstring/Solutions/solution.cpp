#include <string>

class Solution {
public:
    bool validParenthesesSubstring(const std::string &s) {
        for (const std::string &paren : {"[]", "{}", "()"}) {
            for (int i = 0; i < (int)s.size() - 1; ++i) {
                if (s[i] == paren[0] && s[i + 1] == paren[1])
                    return true;
            }
        }
        return false;
    }
};
