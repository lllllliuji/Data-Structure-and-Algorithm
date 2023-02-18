#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

const int N = 100010;

int n, m;
int cat[N];
int f[N];

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cat[i];
    }
    vector<vector<int>> tree(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int ans = 0;
    function<void(int, int)> dfs = [&](int sn, int fa) {
        f[sn] = cat[sn] == 0 ? ((fa == -1) ? 0 : (f[fa] > m ? f[fa] : 0)) : (cat[sn] + (fa == -1 ? 0 : f[fa]));
        bool is_leaf = true;
        for (int u : tree[sn]) {
            if (u != fa) {
                dfs(u, sn);
                is_leaf = false;
            }
        }
        if (is_leaf && f[sn] <= m) {
            // cout << sn << endl;
            ans ++;
        }
    };
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}