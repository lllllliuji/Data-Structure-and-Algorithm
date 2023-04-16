class Solution {
   public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int pos = divisors[0], cnt = 0;
        for (int i = 0; i < divisors.size(); i++) {
            int x = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] % divisors[i] == 0) x++;
            }
            if (x > cnt) {
                pos = divisors[i];
                cnt = x;
            }
            if (x == cnt) {
                pos = min(pos, divisors[i]);
            }
        }
        return pos;
    }
};