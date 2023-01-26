class Solution {
   public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n + 1, 0x3f3f3f3f);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int unique = 0;
            unordered_map<int, int> mp;
            for (int j = i; j >= 0; j--) {
                mp[nums[j]]++;
                if (mp[nums[j]] == 1)
                    unique++;
                else if (mp[nums[j]] == 2)
                    unique--;
                f[i + 1] = min(f[i + 1], f[j] + i - j + 1 - unique + k);
            }
        }
        return f[n];
    }
};