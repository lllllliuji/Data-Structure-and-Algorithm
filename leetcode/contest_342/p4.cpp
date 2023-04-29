class Solution {
   public:
    int minOperations(vector<int>& nums) {
        bool flag = true;
        int ones = 0;
        for (int num : nums) {
            if (num != 1)
                flag = false;
            else
                ones++;
        }
        if (flag) return 0;
        int n = nums.size();
        int x;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                x = nums[i];
            else {
                x = gcd(x, nums[i]);
            }
        }
        if (x != 1) return -1;
        for (int i = 0; i < n - 1; i++) {
            if (gcd(nums[i], nums[i + 1]) == 1) {
                return n - ones;
            }
        }
        int len = n;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = i + 1; j < n; j++) {
                x = gcd(x, nums[j]);
                if (x == 1) {
                    // cout << i << " " << j << endl;
                    len = min(len, j - i);
                }
            }
        }
        return n + len - 1;
    }
};