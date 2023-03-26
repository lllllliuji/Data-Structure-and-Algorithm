class Solution {
   public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        vector<long long> ans;
        for (int q : queries) {
            auto it = lower_bound(nums.begin(), nums.end(), q);
            if (it == nums.end()) {
                ans.push_back(1LL * q * n - sum[n]);
                continue;
            }
            int pos = it - nums.begin();
            long long v = 0;
            v += 1LL * q * pos - sum[pos];
            v += sum[n] - sum[pos] - 1LL * (n - pos) * q;
            ans.push_back(v);
        }
        return ans;
    }
};