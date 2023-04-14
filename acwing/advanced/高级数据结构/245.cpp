#include <algorithm>
#include <iostream>
using namespace std;

const int N = 500010;

int w[N];

struct Node {
    int l, r;
    int sum, lmax, rmax, tmax;
} tr[4 * N];

void pushup(Node& u, Node& l, Node& r) {
    u.sum = l.sum + r.sum;
    u.lmax = max(l.lmax, l.sum + r.lmax);
    u.rmax = max(r.rmax, r.sum + l.rmax);
    u.tmax = max({l.tmax, r.tmax, l.rmax + r.lmax});
}

void pushup(int u) { pushup(tr[u], tr[u << 1], tr[u << 1 | 1]); }

void build(int u, int l, int r) {
    tr[u].l = l;
    tr[u].r = r;
    if (l == r) {
        tr[u].sum = w[l];
        tr[u].lmax = w[l];
        tr[u].rmax = w[l];
        tr[u].tmax = w[l];
    } else {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u] = {x, x, v, v, v, v};
    } else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        if (x > mid) modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid) {
        return query(u << 1, l, r);
    }
    if (l > mid) {
        return query(u << 1 | 1, l, r);
    }
    auto left = query(u << 1, l, r);
    auto right = query(u << 1 | 1, l, r);
    Node res;
    pushup(res, left, right);
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    build(1, 1, n);

    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            if (x > y) swap(x, y);
            cout << query(1, x, y).tmax << endl;
        } else {
            modify(1, x, y);
        }
    }

    return 0;
}