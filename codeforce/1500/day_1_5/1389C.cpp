#include <iostream>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = n;
    for (char a = '0'; a <= '9'; a++) {
        for (char b = '0'; b <= '9'; b++) {
            char u = a, v = b;
            int sum = 0;
            for (auto &c : s) {
                if (c == u) {
                    sum++;
                    swap(u, v);
                }
            }
            if (sum % 2 == 0 || u == v) {
                ans = min(ans, n - sum);
            }
        }
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}