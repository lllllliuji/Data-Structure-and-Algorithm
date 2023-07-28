#pragma once

using namespace std;

const int N = 100;
//p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量, d[]表示x到p[x]的距离
int p[N], size[N], d[N];

void unite(int a, int b) {
    size[find(b)] += size[find(a)];
    p[find(a)] = find(b);
    d[find(a)] = 0; // 视情况而定
}

int find(int x) {
    if (p[x] != x) {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}

void init() {
    for (int i = 0; i < N; i++) {
        p[i] = i;
        size[i] = 1;
        d[i] = 0;
    }
}