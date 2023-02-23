#include <iostream>

using namespace std;

const int N = 100010;
char str[N];
int n, k;

int get(char c) {
    int ans = 0;
    for (int i = 1, j = 1, cnt = 0; i <= n; i++) {
        if (str[i] != c) cnt++;
        while (cnt > k) {
            if (str[j] != c) cnt--;
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    cin >> str + 1;
    cout << max(get('a'), get('b')) << endl;
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