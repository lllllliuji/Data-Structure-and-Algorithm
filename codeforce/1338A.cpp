#include <iostream>

using namespace std;

const int N = 100010;

int m, n;
int arr[N];

void solve() {
    long long diff = 0;
    for (int i = n - 1, minn = arr[i]; i >= 0; i--) {
        diff = max(diff, 0LL + arr[i] - minn);
        minn = min(minn + 0LL, 0LL + arr[i]);
    }
    int cnt = 0;
    for (long long i = 1; i <= diff; i <<= 1) {
        cnt++;
    }
    cout << cnt << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> m;
    while (m--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve();
    }
    return 0;
}