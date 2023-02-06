class Solution {
   public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (const auto& q : queries) {
            int a = q[0], b = q[1];
            deque<int> q1;
            deque<int> q2;
            while (a) {
                q1.push_back(a);
                a /= 2;
            }
            while (b) {
                q2.push_back(b);
                b /= 2;
            }
            while (!q1.empty() && !q2.empty() && q1.back() == q2.back()) {
                q1.pop_back();
                q2.pop_back();
            }
            ans.push_back(q1.size() + q2.size() + 1);
        }
        return ans;
    }
};