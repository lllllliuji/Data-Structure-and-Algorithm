class Solution {
   public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = i; j < n; j++) {
                int z = gcd(x, nums[j]);
                if (z == k) {
                    ans++;
                }
                x = z;
            }
        }
        return ans;
    }
};