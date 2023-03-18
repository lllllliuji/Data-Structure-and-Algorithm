class Solution {
   public:
    int maximizeGreatness(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int len = l + r + 1 >> 1;
            bool flag = true;
            for (int i = 0; i < len; i++) {
                if (nums[i] >= nums[n - len + i]) flag = false;
            }
            if (flag)
                l = len;
            else
                r = len - 1;
        }
        return l;
    }
};