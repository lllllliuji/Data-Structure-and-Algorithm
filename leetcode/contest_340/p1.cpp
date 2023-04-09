class Solution {
   public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> A, B;
        for (int i = 0; i < n; i++) {
            int x = nums[i][i];
            int y = nums[i][n - i - 1];
            bool flagA = x > 1 ? true : false;
            bool flagB = y > 1 ? true : false;
            for (int j = 2; j <= x / j; j++) {
                if ((x % j) == 0) {
                    flagA = false;
                }
            }
            for (int j = 2; j <= y / j; j++) {
                if ((y % j) == 0) {
                    flagB = false;
                }
            }
            if (flagA) A.push_back(x);
            if (flagB) A.push_back(y);
        }
        if (A.empty()) return 0;
        sort(A.begin(), A.end());
        return A.back();
    }
};