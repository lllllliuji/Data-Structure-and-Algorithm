class Solution {
   public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front();
        while (l < r) {
            int mid = l + r >> 1;
            int cnt = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i] - nums[i - 1] <= mid) {
                    cnt++;
                    i++;
                }
            }
            if (cnt >= p)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};