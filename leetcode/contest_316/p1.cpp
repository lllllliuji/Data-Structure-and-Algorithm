class Solution {
   public:
    int get(string t) {
        int ans = (t[0] - '0') * 10 + (t[1] - '0');
        ans *= 60;
        ans += (t[3] - '0') * 10 + (t[4] - '0');

        return ans;
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        vector<vector<int>> g;
        g.push_back({get(event1[0]), get(event1[1])});
        g.push_back({get(event2[0]), get(event2[1])});
        sort(g.begin(), g.end());
        return g[0][1] >= g[1][0];
    }
};