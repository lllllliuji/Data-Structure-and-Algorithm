class Solution {
   public:
    int similarPairs(vector<string>& words) {
        unordered_map<string, int> hash;
        int ans = 0;
        for (const auto& word : words) {
            auto t = help(word);
            ans += hash[t];
            hash[t]++;
        }
        return ans;
    }
    string help(const string& s) {
        unordered_set<char> st(s.begin(), s.end());
        string t = "";
        for (char c : st) t += c;
        sort(t.begin(), t.end());
        return t;
    }
};