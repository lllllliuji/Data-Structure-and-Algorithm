#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;
int n, m;
int arr[N];
int t[N];
int cnt[N];

int lowbit(int x) { return x & -x; }

int query(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += t[i];
    return ans;
}

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) t[i] += c;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    while (m--) {
        int l, r;
        cin >> l >> r;
        add(l, 1);
        add(r + 1, -1);
    }
    sort(arr + 1, arr + n + 1, [](int a, int b) {
        return a > b;
    });
    for (int i = 1; i <= n; i++) {
        cnt[i] = query(i);
    }
    sort(cnt + 1, cnt + n + 1, [](int a, int b) {
        return a > b;
    });
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * arr[i] * cnt[i];
    }
    cout << ans << endl;
    return 0;
}