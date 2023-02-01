class Solution {
   public:
    bool isItPossible(string word1, string word2) {
        vector<int> h1(26), h2(26);
        for (char c : word1) h1[c - 'a']++;
        for (char c : word2) h2[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (h1[i] == 0) continue;
            h1[i]--;
            h2[i]++;
            for (int j = 0; j < 26; j++) {
                if (j != i && h2[j] > 0 || h2[j] > 1) {
                    h1[j]++;
                    h2[j]--;
                    int cnt1 = 0;
                    int cnt2 = 0;
                    for (int k = 0; k < 26; k++) {
                        if (h1[k] > 0) cnt1++;
                    }
                    for (int k = 0; k < 26; k++) {
                        if (h2[k] > 0) cnt2++;
                    }
                    if (cnt1 == cnt2) {
                        return true;
                    }
                    h2[j]++;
                    h1[j]--;
                }
            }
            h2[i]--;
            h1[i]++;
        }
        return false;
    }
};