#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 100010;
vector<vector<pair<int, int>>> g(N);
bool vis[N];
int dis[N];
int cnt[N];
int n, m;

bool spfa() {
    memset(vis, false, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    dis[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first, w = g[u][i].second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    if (dis[n] == 0x3f3f3f3f) return false;
    return true;
}

bool exist_negative_circle() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        vis[i] = true;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first, w = g[u][i].second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return true;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}

int solve() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    if (spfa())
        cout << dis[n] << endl;
    else
        cout << "impossible" << endl;
}