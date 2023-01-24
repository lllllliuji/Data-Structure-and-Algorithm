#pragma once

#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int g[N][N];
int d[N];
bool vis[N];
int n;
int dijkstra(int x) {
    memset(d, 0x3f, sizeof d);
    d[x] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j ++) {
            if (!vis[j] && (u == -1 || d[j] < d[u])) u = j;
        }
        if (u == -1) break;
        vis[u] =true;
        for (int v = 0; v < n; v++) {
            d[v] = min(d[v], d[u] + g[u][v]);
        }
    }
    if (d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}