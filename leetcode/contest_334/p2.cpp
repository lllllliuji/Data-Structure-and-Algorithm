class Solution {
   public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        long long x = 0;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            x = x * 10 + (word[i] - '0');
            if (x % m == 0) ans[i] = 1;
            x = x % m;
        }
        return ans;
    }
};