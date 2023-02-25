#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
    int n;
    string str;
    cin >> n >> str;
    queue<int> one;
    queue<int> zero;
    vector<int> ans(n);

    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            if (one.empty()) {
                ans[i] = cnt;
                zero.push(cnt++);
            } else {
                int t = one.front();
                ans[i] = t;
                one.pop();
                zero.push(t);
            }
        } else {
            if (zero.empty()) {
                ans[i] = cnt;
                one.push(cnt++);
            } else {
                int t = zero.front();
                ans[i] = t;
                zero.pop();
                one.push(t);
            }
        }
    }
    cout << cnt - 1 << endl;
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
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
