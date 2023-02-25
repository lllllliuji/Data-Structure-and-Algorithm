#include <iostream>

using namespace std;

void solve() {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    if (n1 == 0) {
        if (n0 == 0)
            cout << string(n2 + 1, '1') << endl;
        else
            cout << string(n0 + 1, '0') << endl;
        return;
    } else {
        string ans;
        for (int i = 0; i < n1 + 1; i++) {
            if (i & 1) {
                ans += '0';
            } else
                ans += '1';
        }
        ans.insert(1, string(n0, '0'));
        ans.insert(0, string(n2, '1'));
        cout << ans << endl;
    }
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