class Solution {
   public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size(), n = score[0].size();
        vector<int> p;
        for (int i = 0; i < m; i++) {
            p.push_back(i);
        }
        sort(p.begin(), p.end(), [&](int a, int b) { return score[a][k] > score[b][k]; });
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            ans.emplace_back(score[p[i]]);
        }

        return ans;
    }
};