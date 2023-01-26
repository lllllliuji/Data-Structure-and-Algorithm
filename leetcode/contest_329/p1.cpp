class Solution {
   public:
    int alternateDigitSum(int n) {
        string str = to_string(n);
        int ans = 0;
        int b = 1;
        for (char c : str) {
            ans += b * (c - '0');
            b = -b;
        }
        return ans;
    }
};