class Solution {
   public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> hash;
        long long ans = 0;
        for (int i = 0, x = 0; i < nums.size(); i++) {
            x ^= nums[i];
            ans += hash[x];
            hash[x]++;
        }
        ans += hash[0];
        return ans;
    }
};