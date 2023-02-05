class Solution {
   public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int f[n + 1];
        int g[n + 1];
        while (l < r) {
            int mid = (l + r) >> 1;
            memset(f, 0, sizeof f);
            memset(g, 0, sizeof g);
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) {
                    f[i + 1] = g[i] + 1;
                    if (i - 1 >= 0) f[i + 1] = max(f[i + 1], f[i - 1] + 1);
                }
                g[i + 1] = max(g[i], f[i]);
                if (i - 1 >= 0) g[i + 1] = max(g[i + 1], f[i - 1]);
            }
            if (max(f[n], g[n]) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};