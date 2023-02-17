class Solution {
   public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> S(nums.begin(), nums.end());
        int ans = -1;
        for (int num : nums) {
            if (num > 0 && S.count(-num)) {
                ans = max(ans, num);
            }
        }
        return ans;
    }
};