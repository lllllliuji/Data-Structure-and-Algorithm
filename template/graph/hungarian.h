#pragma once
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 510;

int n1, n2, m;

bool vis[N];
int match[N];

bool find(int u, vector<vector<int>> &g) {
    for (int v : g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            if (match[v] == 0 || find(match[v], g)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int solve() {
    cin >> n1 >> n2 >> m;
    vector<vector<int>> g(n1 + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    int ans = 0;
    for (int i = 1; i <= n1; i++) {
        memset(vis, false, sizeof vis);
        if (find(i, g)) ans++;
    }
    cout << ans << endl;
    return 0;
}