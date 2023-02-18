class Solution {
   public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minn = *min_element(nums.begin(), nums.end() - 2);
        int maxx = *max_element(nums.begin(), nums.end() - 2);
        int ans = 0x3f3f3f3f;
        ans = min(ans, maxx - minn);
        minn = *min_element(nums.begin() + 2, nums.end());
        maxx = *max_element(nums.begin() + 2, nums.end());
        ans = min(ans, maxx - minn);
        minn = *min_element(nums.begin() + 1, nums.end() - 1);
        maxx = *max_element(nums.begin() + 1, nums.end() - 1);
        ans = min(ans, maxx - minn);
        return ans;
    }
};