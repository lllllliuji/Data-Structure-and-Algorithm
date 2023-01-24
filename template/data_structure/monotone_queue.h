#pragma once

bool check_out(int);
bool check(int, int);

void monotone_queue(int q[], int n) {
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        while (hh <= tt && check_out(q[hh])) hh++;  // 判断队头是否滑出窗口
        while (hh <= tt && check(q[tt], i)) tt--;
        q[++tt] = i;
    }
}