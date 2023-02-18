class Solution {
   public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> S(nums.begin(), nums.end());

        for (int i = 1; i < INT_MAX; i <<= 1) {
            if (!S.count(i)) return i;
        }
        return -1;
    }
};