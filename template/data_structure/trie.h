#pragma once

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int child[N][26], cnt[N], idx;

void insert(string &str) {
    int p = 0;
    for (char ch : str) {
        int u = ch - 'a';
        if (!child[p][u]) child[p][u] = ++idx;
        p = child[p][u];
    }
    cnt[p]++;
}

int query(string &str) {
    int p = 0;
    for (char ch : str) {
        int u = ch - 'a';
        if (!child[p][u]) return 0;
        p = child[p][u];
    }
    return cnt[p];
}

int solve() {
    int n;
    cin >> n;
    while (n--) {
        string op, str;
        cin >> op >> str;
        if (op == "I") {
            insert(str);
        } else {
            cout << query(str) << endl;
        }
    }
    return 0;
}