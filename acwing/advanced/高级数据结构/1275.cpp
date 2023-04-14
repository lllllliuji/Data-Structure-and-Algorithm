#include <iostream>

using namespace std;

const int N = 200010;

struct Node {
    int l, r;
    int v;  // 区间[l,r]中的最大值
} tr[4 * N];

// 由子节点的信息，来更新父节点的信息
void pushup(int u) { tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v); }

void build(int u, int l, int r) {
    tr[u].l = l;
    tr[u].r = r;
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;  // 树中节点，已经被完全包含在[l, r]中了
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if (l <= mid) v = query(u << 1, l, r);
    if (r > mid) v = max(v, query(u << 1 | 1, l, r));
    return v;
}

void modify(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x)
        tr[u].v = v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int m, p;
    cin >> m >> p;
    build(1, 1, m);

    int n = 0, last = 0;
    while (m--) {
        int x;
        string op;
        cin >> op >> x;
        if (op[0] == 'Q') {
            last = query(1, n - x + 1, n);
            cout << last << endl;
        } else {
            modify(1, n + 1, (0LL + last + x) % p);
            n++;
        }
    }
    return 0;
}