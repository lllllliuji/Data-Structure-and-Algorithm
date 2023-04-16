class Solution {
   public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> f(n);
        for (int i = 0, x = 0; i < n; i++) {
            x = max(x, nums[i]);
            f[i] = nums[i] + x;
        }
        vector<long long> ans(n);
        ans[0] = f[0];
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + f[i];
        }
        return ans;
    }
};