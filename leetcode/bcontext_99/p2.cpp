class Solution {
   public:
    long long coloredCells(int n) {
        long long x = 2 * (n - 1) + 1;
        long long sum = 0;
        long long y = 0;
        for (int i = x - 2; i >= 0; i -= 2) {
            y += i;
        }
        return x + 2 * y;
    }
};