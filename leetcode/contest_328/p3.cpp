class Solution {
   public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        long long total = 0;
        long long ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            hash[nums[i]]++;
            total += hash[nums[i]] - 1;
            while (j <= i && total >= k) {
                hash[nums[j]]--;
                total -= hash[nums[j]];
                j++;
            }
            ans += j;
        }

        return ans;
    }
};