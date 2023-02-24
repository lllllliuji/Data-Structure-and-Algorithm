#include <iostream>

using namespace std;

const int N = 200010;

int arr[N];
int f[N];
int g[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        f[i] = g[i] = 0;
    }
    f[0] = 0x3f3f3f3f;
    g[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = g[i - 1] + arr[i];
        g[i] = f[i - 1];
        if (i > 1) {
            f[i] = min(f[i], g[i - 2] + arr[i] + arr[i - 1]);
            g[i] = min(g[i], f[i - 2]);
        }
    }
    cout << min(f[n], g[n]) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}