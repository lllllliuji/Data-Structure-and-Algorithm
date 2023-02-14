class Solution {
   public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0, j = 0; i < n; i++) {
            hash[nums[i]]++;
            sum += nums[i];
            while (i - j + 1 > k) {
                hash[nums[j]]--;
                sum -= nums[j];
                if (hash[nums[j]] == 0) hash.erase(nums[j]);
                j++;
            }
            if (i - j + 1 == k && hash.size() == k) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};