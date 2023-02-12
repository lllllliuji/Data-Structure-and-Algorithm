class Solution {
   public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto high = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            if (low != nums.end()) {
                ans += high - low;
            }
        }
        return ans;
    }
};