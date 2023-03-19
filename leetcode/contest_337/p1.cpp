class Solution {
   public:
    vector<int> evenOddBit(int n) {
        int odd = 0, even = 0;
        for (int i = 0; i < 31; i++) {
            if (i & 1) {
                even += ((n >> i) & 1);
            } else {
                odd += ((n >> i) & 1);
            }
        }
        return {odd, even};
    }
};