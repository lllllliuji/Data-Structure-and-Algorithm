#pragma once

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
// g[i][j] = {v, dis}
int dijkstra(int x, vector<vector<pair<int,int >>> &g) {
    // base index = 1, modify if base index = 0
    vector<int> dis(n + 1, 0x3f3f3f3f);
    dis[x] = 0;
    using E = pair<int, int>;
    priority_queue<E, vector<E>, greater<>> q;
    q.push({0, x});
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        int du = t.first, u = t.second;
        if (dis[u] < du) {
            continue;
        }
        for (auto& e : g[u]) {
            int v = e.first, dv = e.second + du;
            if (dv < dis[v]) {
                dis[v] = dv;
                q.push({dv, v});
            }
        }
    }
    return dis[n] == 0x3f3f3f3f ? -1 : dis[n];
}