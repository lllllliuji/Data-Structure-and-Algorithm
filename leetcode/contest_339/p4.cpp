class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int K) {
        vector<int> ans(n, -1);
        if (K == 1) {
            // 处理特殊情况 k = 1
            ans[p] = 0;
            return ans;
        }

        unordered_set<int> ban;
        for (int x : banned) ban.insert(x);

        // 把除了 p 和 banned 的所有位置，按奇偶性放进两个 set 里
        // 这些就是我们还没被跳到的位置
        set<int> st[2];
        for (int i = 0; i < n; i++) if (i != p && ban.count(i) == 0) st[i % 2].insert(i);

        // bfs
        queue<int> q;
        q.push(p); ans[p] = 0;
        while  (!q.empty()) {
            int now = q.front(); q.pop();
            
            // 计算可以跳的范围
            int L, R;
            L = max(-(K - 1), K - 1 - now * 2);
            R = min(K - 1, -(K - 1) + (n - now - 1) * 2);

            // 寻找第一个大于等于 now + L 的位置，并开始枚举后面连续的位置
            int x = (now + (K - 1)) % 2;
            auto it = st[x].lower_bound(now + L);
            while (it != st[x].end()) {
                // 遇到了第一个大于 now + R 的位置，结束枚举
                if (*it > now + R) break;
                // 这个位置还没被跳过，但是可以从 now 一步跳过来
                // 更新答案，并从 set<int> 里去掉
                ans[*it] = ans[now] + 1;
                q.push(*it);
                it = st[x].erase(it);
            }
        }

        return ans;
    }
};
