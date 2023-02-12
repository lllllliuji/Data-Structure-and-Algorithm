class Solution {
   public:
    int minimumScore(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int> prefix(m + 1);
        vector<int> suffix(m + 1);
        for (int i = 0, j = 0, len = 0; i < m; i++) {
            while (i < m && j < n && s[i] != t[j]) {
                prefix[i] = len;
                i++;
            }
            if (j < n) {
                len++;
                j++;
            }
            if (i < m) prefix[i] = len;
        }
        for (int i = m - 1, j = n - 1, len = 0; i >= 0; i--) {
            while (i >= 0 && j >= 0 && s[i] != t[j]) {
                suffix[i] = len;
                i--;
            }
            if (j >= 0) {
                len++;
                j--;
            }
            if (i >= 0) {
                suffix[i] = len;
            }
        }
        int ans = n;
        for (int i = 0; i < m; i++) {
            ans = min(ans, n - suffix[i]);
            ans = min(ans, max(0, n - prefix[i] - suffix[i + 1]));
        }
        return ans;
    }
};