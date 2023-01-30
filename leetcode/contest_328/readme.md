# p1 数组元素和与数字和的绝对差
* 暴力

# p2 子矩阵元素加 1
* 二位差分数组，前缀和就是答案 f[r1][c1]++, f[r2 + 1][c2 + 1]--, f[r2 + 1][c1]--, f[r1][c2 + 1]--

# p3 统计好子数组的数目
* 双指针，注意不重不漏的统计每一子数组
```
long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        long long total = 0;
        long long ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            hash[nums[i]]++;
            total += hash[nums[i]] - 1;
            while (j <= i && total >= k) {
                hash[nums[j]]--;
                total -= hash[nums[j]];
                j++;
            }
            ans += j; // think about here， 不重不漏
        }
        return ans;
```

# p4 最大价值和与最小价值和的差值
* 树形dp, 返回带叶子节点的直径，和不带叶子节点的直径, 注意写法
```
class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n, vector<int>());
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        long long ans = 0;
        function<pair<long long, long long>(int, int)> dfs = [&](int u, int fa) -> pair<long long, long long> {
            long long p = price[u], has_leaf = p, no_leaf = 0;
            for (int v : g[u]) {
                if (v != fa) {
                    auto [h, n] = dfs(v, u);
                    ans = max({ans, has_leaf + n, no_leaf + h});
                    has_leaf = max(has_leaf, h + p);
                    no_leaf = max(no_leaf, n + p);
                }
            }
            return {has_leaf, no_leaf};
        };
        dfs(0, -1);
        return ans;
    }
};