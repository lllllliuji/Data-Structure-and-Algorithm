#pragma

const int N = 100010;

int t[N];

int n, m;

int lowbit(int x) { return x & -x; }

int query(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += t[i];
    return ans;
}

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) t[i] += c;
}