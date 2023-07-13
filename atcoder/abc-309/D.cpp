#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int dijkstra(int start, vector<unordered_set<int>> &g) {
    int n = g.size();
    vector<int> d(n, 0x3f3f3f3f);
    d[start] = 0;
    using E = pair<int, int>;
    priority_queue<E, vector<E>, greater<E>> q;
    q.push({0, start});
    while (!q.empty()) {
        auto [du, u] = q.top();
        q.pop();
        if (d[u] < du) continue;
        for (int v : g[u]) {
            if (du + 1 < d[v]) {
                d[v] = du + 1;
                q.push({d[v], v});
            }
        }
    }
    int mx = -1;
    for (int i = 0; i < n; i++) {
        if (d[i] != 0x3f3f3f3f) {
            mx = max(mx, d[i]);
        }
        // cout << i << " " << d[i] << endl;
    }
    return mx;
}

void solve() {
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector<unordered_set<int>> g(n1 + n2 + 10, unordered_set<int>());
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a != b) {
            g[a].insert(b);
            g[b].insert(a);
        }
    }
    int x = dijkstra(1, g);
    int y = dijkstra(n1 + n2, g);
    cout << x + y + 1 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout << setprecision(10) << fixed;
    solve();
    return 0;
}