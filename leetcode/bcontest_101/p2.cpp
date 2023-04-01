class Solution {
   public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> hash;
        for (int i = 0; i < chars.size(); i++) {
            hash[chars[i]] = vals[i];
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (!hash.count(c)) {
                hash[c] = (c - 'a') + 1;
            }
        }
        int ans = 0;
        int n = s.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + hash[s[i]];
        }
        int mn = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            ans = max(ans, hash[s[i]]);
            ans = max(ans, sum[i + 1]);
            if (mn != INT_MAX) {
                ans = max(ans, sum[i + 1] - mn);
            }
            mn = min(sum[i + 1], mn);
        }
        return ans;
    }
};