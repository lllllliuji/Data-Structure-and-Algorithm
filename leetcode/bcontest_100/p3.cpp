class Solution {
   public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        using E = pair<int, int>;
        priority_queue<E, vector<E>, greater<E>> q;
        int n = nums.size();
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            q.push({nums[i], i});
        }
        while (!q.empty()) {
            auto [v, i] = q.top();
            q.pop();
            if (vis[i]) continue;
            vis[i] = true;
            ans += v;
            int prev = i - 1, next = i + 1;
            if (prev >= 0 && !vis[prev]) {
                vis[prev] = true;
            }
            if (next < n && !vis[next]) {
                vis[next] = true;
            }
        }
        return ans;
    }
};