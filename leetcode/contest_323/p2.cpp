class Solution {
   public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_set<long> S(nums.begin(), nums.end());
        unordered_map<long, bool> vis;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (!vis[nums[i]]) {
                long x = nums[i];
                int cnt = 1;
                while (x <= 100000 && S.count(x * x)) {
                    // cout << x << " " << x * x << " ";
                    x = x * x;
                    cnt++;
                }
                ans = max(ans, cnt);
                vis[nums[i]] = true;
            }
        }
        return ans == 1 ? -1 : ans;
    }
};