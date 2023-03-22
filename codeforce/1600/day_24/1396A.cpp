#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int N = 100010;
int arr[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    if (n == 1) {
        for (int i = 0; i < 3; i++) {
            cout << "1 1" << endl;
            cout << -arr[1] << endl;
            arr[1] = 0;
        }
        return;
    }
    cout << "1 1" << endl;
    cout << -arr[1] << endl;
    cout << "1 " << n << endl;
    arr[1] = 0;
    for (int i = 1; i <= n; i++) {
        cout << -1LL * n * arr[i] << " ";
    }
    cout << endl;
    cout << "2 " << n << endl;
    for (int i = 2; i <= n; i++) {
        cout << 1LL * (n - 1) * arr[i] << " ";
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}