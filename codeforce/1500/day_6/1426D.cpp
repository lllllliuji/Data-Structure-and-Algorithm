#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 200010;

int arr[N];

void solve() {
    int n;
    cin >> n;
    unordered_set<long long> S;
    S.insert(0);
    int ans = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (S.find(sum) == S.end()) {
            S.insert(sum);
        } else {
            ans++;
            S.clear();
            sum = arr[i];
            S.insert({0, sum});
        }
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}