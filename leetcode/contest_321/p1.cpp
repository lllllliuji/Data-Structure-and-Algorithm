class Solution {
   public:
    int pivotInteger(int n) {
        vector<int> sum(n + 1);
        int total = 0;
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + i;
            total += i;
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (sum[i] == total - sum[i - 1]) {
                return i;
            }
        }
        return -1;
    }
};