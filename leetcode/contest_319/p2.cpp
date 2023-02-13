class Solution {
   public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = i; j < n; j++) {
                if (i == j) {
                    x = nums[i];
                    if (x == k) ans++;
                } else {
                    x = lcm(x, nums[j]);
                    if (x == k) ans++;
                    if (x > k) break;
                }
            }
        }
        return ans;
    }
};