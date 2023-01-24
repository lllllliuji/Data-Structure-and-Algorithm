#pragma once

#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int N = 100;
vector<int> d;
vector<vector<int>> g;

bool top_sort(int n) {
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            d[g[i][j]]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < g.size(); i++) {
        if (d[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        n--;
        for (int x : g[t]) {
            d[x]--;
            if (d[x] == 0) {
                q.push(x);
            }
        }
    }
    return n == 0;
}