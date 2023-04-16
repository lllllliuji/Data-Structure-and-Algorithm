class Solution {
   public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int pos = 0, cnt = 0;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int x = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) x++;
            }
            if (x > cnt) {
                cnt = x;
                pos = i;
            }
        }
        return {pos, cnt};
    }
};