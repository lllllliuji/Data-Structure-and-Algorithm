class Solution {
   public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> cnt;
        function<void(int)> dfs = [&](int u) {
            if (u == n) {
                return;
            }
            // cout << u << endl;
            dfs(u + 1);
            if (cnt[nums[u] - k] == 0 && cnt[nums[u] + k] == 0) {
                ans++;
                cnt[nums[u]]++;
                dfs(u + 1);
                cnt[nums[u]]--;
            }
        };
        dfs(0);
        return ans;
    }
};