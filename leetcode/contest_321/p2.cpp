class Solution {
   public:
    int appendCharacters(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        while (i < m) {
            if (j >= n) break;
            while (i < m && s[i] != t[j]) i++;
            if (i < m) j++;
            i++;
        }
        return n - j;
    }
};