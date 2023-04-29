class Solution {
   public:
    int maximizeSum(vector<int>& nums, int k) {
        int x = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < k; i++) cnt += i;
        return k * x + cnt;
    }
};