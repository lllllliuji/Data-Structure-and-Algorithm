class Solution {
   public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        vector<int> ans(n);
        for (int i = n - 1, x = 0; i >= 0; i--) {
            ans[i] = abs(x - sum[i]);
            x += nums[i];
        }
        return ans;
    }
};