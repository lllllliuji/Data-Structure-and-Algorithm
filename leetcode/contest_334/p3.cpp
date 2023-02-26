class Solution {
   public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        vector<int> vis(n, false);
        for (int i = 0, j = n / 2; i < n / 2 && j < n; i++, j++) {
            while (j < n && nums[j] < 2 * nums[i]) {
                j++;
            }
            if (j < n) {
                ans += 2;
            }
        }
        return ans;
    }
};