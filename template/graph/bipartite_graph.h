#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int N = 100010;

int n, m;
int color[N];

bool dfs(int u, int c, vector<vector<int>> &g) {
    color[u] = c;
    for (int v : g[u]) {
        if (!color[v]) {
            if (!dfs(v, 3 - c, g)) return false;
        } else if (color[v] == c)
            return false;
    }
    return true;
}
int solve() {
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!dfs(i, 1, g)) {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}