class Solution {
   public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        s = s + s;
        int n = s.size();
        int ans = n;
        unordered_map<int, int> hash;

        auto check = [&]() { return hash['a'] >= k && hash['b'] >= k && hash['c'] >= k; };
        int i = 0, j = 0;
        while (i < n) {
            if (check()) ans = min(ans, i - j);
            while (check() && i >= n / 2 && j < n / 2 - 1) {
                ans = min(ans, i - j);
                hash[s[j]]--;
                j++;
            }
            hash[s[i]]++;
            i++;
        }
        return ans > n / 2 ? -1 : ans;
    }
};