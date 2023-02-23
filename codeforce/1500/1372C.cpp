#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int cnt = 0, flag = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] != i) {
            if (!flag) cnt++, flag = 1;
        } else
            flag = 0;
    }
    if (cnt == 0)
        cout << 0 << endl;
    else if (cnt == 1)
        cout << 1 << endl;
    else
        cout << 2 << endl;
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
