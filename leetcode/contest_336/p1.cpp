class Solution {
   public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        unordered_set<char> S{'a', 'e', 'i', 'o', 'u'};
        for (int i = left; i <= right; i++) {
            if (S.count(words[i].front()) && S.count(words[i].back())) {
                ans++;
            }
        }
        return ans;
    }
};