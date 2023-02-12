class Solution {
   public:
    int get(string& s, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            ans = 2 * ans + (s[i] - '0');
        }
        return ans;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> ans;
        unordered_map<int, pair<int, int>> his;
        for (int i = 1; i <= 31; i++) {
            for (int j = 0; i + j - 1 < n; j++) {
                int x = get(s, j, i + j - 1);
                if (!his.count(x)) {
                    his[x] = {j, i + j - 1};
                }
            }
        }
        for (auto& q : queries) {
            int x = q[0] ^ q[1];
            if (!his.count(x)) {
                ans.push_back({-1, -1});
            } else {
                ans.push_back({his[x].first, his[x].second});
            }
        }
        return ans;
    }
};