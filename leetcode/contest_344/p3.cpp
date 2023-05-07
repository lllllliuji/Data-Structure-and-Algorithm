class Solution {
   public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        vector<int> color(n);
        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < q.size(); i++) {
            int idx = q[i][0], c = q[i][1];
            if (idx > 0 && color[idx - 1] != 0) {
                if (color[idx - 1] == color[idx]) cnt--;
            }
            if (idx + 1 < n && color[idx + 1] != 0) {
                if (color[idx + 1] == color[idx]) cnt--;
            }
            color[idx] = c;
            if (idx > 0 && color[idx - 1] == c) cnt++;
            if (idx + 1 < n && color[idx + 1] == c) cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};