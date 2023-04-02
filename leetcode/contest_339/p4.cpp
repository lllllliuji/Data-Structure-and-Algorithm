class Solution {
   public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        unordered_set<int> ban(banned.begin(), banned.end());
        set<int> st[2];
        for (int i = 0; i < n; i++) {
            if (i != p && !ban.count(i)) {
                st[i % 2].insert(i);
            }
        }
        st[0].insert(n);
        st[1].insert(n);
        vector<int> ans(n, -1);
        queue<int> q;
        int step = 0;
        q.push(p);
        while (!q.empty()) {
            int t = q.size();
            while (t--) {
                int i = q.front();
                q.pop();
                ans[i] = step;
                // i 交换的位置 j, 满足 i + j = 左端点 + 右端点
                int mn = max(i - k + 1, k - 1 - i);
                int mx = min(i + k - 1, n - 1 + (n - k) - i);
                auto& s = st[mn % 2];
                for (auto it = s.lower_bound(mn); *it <= mx; it = s.erase(it)) {
                    q.push(*it);
                }
            }
            step++;
        }
        return ans;
    }
};