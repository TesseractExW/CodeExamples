#include <stack>
#include <utility>
#include <vector>

class Solution {
private:
    std::vector<int> parents;
    std::vector<int> sizes;

    std::stack<std::pair<int, int>> unite_stack;
    std::stack<int> top_stack;

    int find(int i) {
        if (parents[i] == i) {
            return i;
        } else {
            return find(parents[i]);
        }
    }

    bool unite(int i, int j) {
        int a = find(i);
        int b = find(j);

        if (a == b) {
            return false;
        } else if (sizes[a] < sizes[b]) {
            return unite(b, a);
        }

        parents[b] = a;
        sizes[a] += sizes[b];

        unite_stack.emplace(a, b);

        int curr_top = top_stack.top();
        if (sizes[a] > sizes[curr_top] || (sizes[a] == sizes[curr_top] && a < curr_top)) {
            curr_top = a;
        }
        top_stack.push(curr_top);
        return true;
    }

    void pop() {
        auto [a, b] = unite_stack.top();
        unite_stack.pop();
        top_stack.pop();

        parents[b] = b;
        sizes[a] -= sizes[b];
    }

public:
    std::vector<int> mergeGame(int n, std::vector<std::vector<int>> &queries) {
        sizes.resize(n);
        parents.resize(n);
        top_stack.push(0);

        for (int i = 0; i < n; ++i) {
            sizes[i] = 1;
            parents[i] = i;
        }

        std::vector<int> answer;
        for (std::vector<int> &query : queries) {
            if (query[0] == 0) {
                answer.push_back(top_stack.top());
            } else if (query[0] == 1) {
                unite(query[1], query[2]);
            } else {
                pop();
            }
        }
        return answer;
    }
};
