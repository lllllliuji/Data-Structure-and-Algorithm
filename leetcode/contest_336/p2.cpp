class Solution {
   public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans += sum > 0;
        }
        return ans;
    }
};