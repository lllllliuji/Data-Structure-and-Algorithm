#include <iostream>

using namespace std;

int base[10];

int get(int v) {
    int ans = 0;
    int d = 0;
    do {
        ans += (v %  10) * base[d++];
        v /= 10;
    } while (v);
    return ans;
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << get(r) - get(l) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 0, x = 1; i < 10; i++) {
        base[i] = x;
        x = 10 * x + 1;
    }
    while (t--) {
        solve();
    }
    return 0;
}