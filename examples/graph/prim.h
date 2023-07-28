#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
bool vis[N];
int dis[N];
int g[N][N];

int prim() {
    memset(vis, false, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (u == -1 || dis[j] < dis[u])) {
                u = j;
            }
        }
        vis[u] = true;
        if (i > 0 && dis[u] == INF) return INF;
        if (i > 0) ans += dis[u];
        for (int j = 1; j <= n; j++) {
            dis[j] = min(dis[j], g[u][j]);
        }
    }
    return ans;
}

int solve() {
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = g[b][a] = min(g[a][b], w);
    }
    int t = prim();
    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}