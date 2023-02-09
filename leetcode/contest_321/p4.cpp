class Solution {
   public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int pos = find(nums.begin(), nums.end(), k) - nums.begin();
        unordered_map<int, int> hash;
        hash[0] = 1;
        for (int i = pos - 1, sum = 0; i >= 0; i--) {
            sum += nums[i] > k ? 1 : -1;
            hash[sum]++;
        }
        int ans = hash[0] + hash[1];
        for (int i = pos + 1, sum = 0; i < n; i++) {
            sum += nums[i] > k ? 1 : -1;
            ans += hash[-sum] + hash[-sum + 1];
        }
        return ans;
    }
};