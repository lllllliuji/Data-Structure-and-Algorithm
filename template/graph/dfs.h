#pragma once

#include <iostream>
#include <vector>

using namespace std;

const int N = 100;
bool vis[N];
vector<vector<int>> g;
void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}
