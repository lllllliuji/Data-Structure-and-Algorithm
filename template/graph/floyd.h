#pragma once

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100;
const int INF = 0x3f3f3f3f;
int n;
int d[N][N];
void init() {
    // 初始化：
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
}
void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}