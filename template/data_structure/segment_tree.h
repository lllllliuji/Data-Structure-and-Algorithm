#pragma once
#include <iostream>

using namespace std;

// 单点修改，区间求和
namespace SegmentTree {
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
}  // namespace SegmentTree

// 区间修改，区间求和
namespace SegmentTreeLazy {
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
}  // namespace SegmentTreeLazy
