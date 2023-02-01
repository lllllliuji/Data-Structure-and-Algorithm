class Solution {
   public:
    int maximumCount(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num : nums) {
            if (num < 0) a++;
            if (num > 0) b++;
        }
        return max(a, b);
    }
};