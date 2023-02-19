#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010;

int w[N];
struct Node {
    int l, r;
    LL sum, lazy;
} tr[4 * N];

void pushup(int u) { tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum; }

void pushdown(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.lazy) {
        left.lazy += root.lazy;
        left.sum += (left.r - left.l + 1LL) * root.lazy;
        right.lazy += root.lazy;
        right.sum += (right.r - right.l + 1LL) * root.lazy;
        root.lazy = 0;
    }
}

void build(int u, int l, int r) {
    tr[u].l = l;
    tr[u].r = r;
    if (l == r) {
        tr[u].sum = w[l];
        tr[u].lazy = 0;
    } else {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int d) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += (tr[u].r - tr[u].l + 1LL) * d;
        tr[u].lazy += d;
    } else {
        // 分裂
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, d);
        if (r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

LL query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].sum;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL sum = 0;
    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];

    build(1, 1, n);

    while (m--) {
        int l, r, d;
        string op;
        cin >> op >> l >> r;
        if (op[0] == 'C') {
            cin >> d;
            modify(1, l, r, d);
        } else {
            cout << query(1, l, r) << endl;
        }
    }
    return 0;
}
