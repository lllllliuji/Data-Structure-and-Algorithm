#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 500010;

LL w[N];
struct Node {
    int l, r;
    LL sum, d;
} tr[N * 4];

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

void pushup(Node &u, Node &l, Node &r) {
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
}

void pushup(int u) { pushup(tr[u], tr[u << 1], tr[u << 1 | 1]); }

void build(int u, int l, int r) {
    if (l == r) {
        LL b = w[r] - w[r - 1];
        tr[u] = {l, r, b, b};
    } else {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, LL v) {
    if (tr[u].l == x && tr[u].r == x) {
        LL b = tr[u].sum + v;
        tr[u] = {x, x, b, b};
    } else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid)
            return query(u << 1, l, r);
        else if (l > mid)
            return query(u << 1 | 1, l, r);
        else {
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
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

    int l, r;
    LL d;
    string op;
    while (m--) {
        cin >> op >> l >> r;
        if (op[0] == 'Q') {
            auto left = query(1, 1, l);
            Node right({0, 0, 0, 0});
            if (l + 1 <= r) right = query(1, l + 1, r);
            cout << abs(gcd(left.sum, right.d)) << endl;
        } else {
            cin >> d;
            modify(1, l, d);
            if (r + 1 <= n) modify(1, r + 1, -d);
        }
    }
    return 0;
}
