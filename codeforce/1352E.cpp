#include <cstring>
#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 8080;
int arr[N];
bool exist[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(exist, false, sizeof exist);
    for (int i = 1; i <= n; i++) {
        int sum = arr[i];
        for (int j = i + 1; j <= n; j++) {
            sum += arr[j];
            if (sum > n) break;
            exist[sum] = true;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (exist[arr[i]]) cnt++;
    }
    cout << cnt << endl;
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