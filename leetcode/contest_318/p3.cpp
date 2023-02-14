class Solution {
   public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        auto func = [&](int a, int b) {
            if (costs[a] != costs[b]) {
                return costs[a] > costs[b];
            }
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(func)> q(func);
        vector<bool> vis(n, false);
        int i = 0, j = n - 1;
        while (i < candidates) {
            q.push(i);
            vis[i] = true;
            i++;
        }
        while (n - 1 - j < candidates) {
            if (!vis[j]) {
                q.push(j);
                vis[j] = true;
            }
            j--;
        }
        long long ans = 0;
        while (k--) {
            auto t = q.top();
            q.pop();
            ans += costs[t];
            if (i > j) continue;
            if (t < i) {
                q.push(i++);
            } else {
                q.push(j--);
            }
        }
        return ans;
    }
};