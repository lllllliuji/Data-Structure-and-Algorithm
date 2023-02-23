#include <iostream>

using namespace std;

const int N = 2020;
int arr[N];

void solve() {
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        x ^= arr[i];
    }
    bool flag = false;
    for (int i = 0, u = 0; i < n; i++) {
        u ^= arr[i];
        if (u == (x ^ u)) {
            flag = true;
            break;
        }
    }
    for (int i = 0, u = 0; i < n; i++) {
        u ^= arr[i];
        for (int j = i + 1, v = 0; j < n; j++) {
            v ^= arr[j];
            if (u == v && (x ^ u ^ v) == u) {
                flag = true;
                break;
            }
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
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