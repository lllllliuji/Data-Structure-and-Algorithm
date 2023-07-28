#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 510;
const int M = 10010;
int n, m, k;
int dis[N], backup[N];
struct Edge {
    int a, b, w;
} edges[M];

// 求 1 -> n的最短距离，最多通过k条边, 允许存在负边
int bellman_ford() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for (int i = 0; i < k; i++) {
        memcpy(backup, dis, sizeof dis);
        for (int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dis[b] = min(dis[b], backup[a] + w);
        }
    }
    if (dis[n] > 0x3f3f3f3f / 2)
        cout << "impossible" << endl;
    else
        cout << dis[n] << endl;
}

int solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }
    bellman_ford();
    return 0;
}