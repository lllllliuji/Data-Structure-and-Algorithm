class Solution {
   public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        function<int(int)> dfs = [&](int u) -> int {
            if (u > n) {
                return 0;
            }
            int left = dfs(2 * u);
            int right = dfs(2 * u + 1);
            ans += abs(left - right);
            return max(left, right) + cost[u - 1];
        };
        dfs(1);
        return ans;
    }
};