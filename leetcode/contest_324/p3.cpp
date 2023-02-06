class Solution {
   public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> d(n + 1);
        vector<set<int>> g(n + 1, set<int>());
        for (auto& e : edges) {
            d[e[0]]++;
            d[e[1]]++;
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (d[i] & 1) odd.push_back(i);
        }
        if (odd.size() == 0) return true;
        if (odd.size() == 2) {
            if (g[odd.front()].count(odd.back())) {
                for (int i = 1; i <= n; i++) {
                    if (i != odd[0] && i != odd[1]) {
                        bool flag = true;
                        if (g[i].count(odd[0]) || g[i].count(odd[1])) {
                            flag = false;
                        }
                        // for (int x : g[i]) {
                        //     if (g[x].count(odd[0]) || g[x].count(odd[1])) {
                        //         flag = false;
                        //     }
                        // }
                        if (flag) {
                            return true;
                        }
                    }
                }
                return false;
            }
            return true;
        } else if (odd.size() == 4) {
            int total = 0;
            for (int i = 0; i < 4; i++) {
                int cnt = 0;
                for (int j = 0; j < 4; j++) {
                    if (i == j) continue;
                    if (g[odd[i]].count(odd[j])) cnt++;
                }
                if (cnt >= 3) return false;
                total += cnt;
            }
            total /= 2;
            if (total == 3) {
                for (int i = 0; i < 4; i++) {
                    int cnt = 0;
                    for (int j = 0; j < 4; j++) {
                        if (i == j) continue;
                        if (g[odd[i]].count(odd[j])) cnt++;
                    }
                    if (cnt >= 3) return false;
                    if (cnt == 0) return false;
                }
            }
            return true;
        }
        return false;
    }
};