#include <queue>
#include <utility>
#include <vector>

class Solution {
    using Graph = std::vector<std::vector<std::pair<int, int>>>;

private:
    // clang-format off
    bool canReach(
        Graph &graph,
        std::vector<int> &fuel,
        std::vector<int> &order,
        long long capacity) 
    {
        // clang-format on
        std::vector<long long> dp(order.size(), -1);
        dp[0] = 0;

        for (int u : order) {
            if (dp[u] < 0)
                continue;
            dp[u] = std::min(dp[u] + fuel[u], capacity);
            for (auto [v, dist] : graph[u]) {
                if (dp[u] >= dist)
                    dp[v] = std::max(dp[v], dp[u] - dist);
            }
        }
        return dp.back() >= 0;
    }

    std::vector<int> getOrder(Graph &graph, std::vector<int> &indeg) {
        std::queue<int> queue;
        std::vector<int> order;

        for (int i = 0; i < (int)graph.size(); ++i) {
            if (indeg[i] == 0)
                queue.push(i);
        }
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            order.push_back(u);

            for (auto [v, dist] : graph[u]) {
                if (--indeg[v] == 0)
                    queue.push(v);
            }
        }
        return order;
    }

public:
    // clang-format off
    long long minimumTankCapacity(
        int n,
        std::vector<std::vector<int>> &edges,
        std::vector<int> &fuel)
    {
        // clang-format on
        std::vector<int> indeg(n, 0);
        Graph graph(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int dist = edge[2];

            graph[u].emplace_back(v, dist);
            ++indeg[v];
        }

        std::vector<int> order = getOrder(graph, indeg);

        long long low = 0;
        long long high = 1e11;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (canReach(graph, fuel, order, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return canReach(graph, fuel, order, low) ? low : -1;
    }
};
