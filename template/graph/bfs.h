#pragma once

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 100;
bool vis[N];
vector<vector<int>> g;

void bfs(int root) {
    queue<int> q;
    vis[root] = true;
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}