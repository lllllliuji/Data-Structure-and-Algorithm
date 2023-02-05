class Solution {
   public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> s{'a', 'e', 'i', 'o', 'u'};
        auto check = [&](const string& str) { return s.count(str.front()) && s.count(str.back()); };
        int n = words.size();
        vector<long> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i];
            if (check(words[i])) sum[i + 1]++;
        }
        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(sum[q[1] + 1] - sum[q[0]]);
        }

        return ans;
    }
};