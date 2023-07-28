#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int n, m;
int p[N];
struct Edge {
    int a, b, w;
    bool operator<(const Edge &edge) const { return w < edge.w; }
} edges[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++) p[i] = i;
    int ans = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a);
        b = find(b);
        if (a != b) {
            p[a] = b;
            ans += w;
            cnt++;
        }
    }
    if (cnt < n - 1) return INF;
    return ans;
}
int solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }

    int t = kruskal();
    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}
