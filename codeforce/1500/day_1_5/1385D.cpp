#include <iostream>
#include <vector>

using namespace std;

int count(string& str, int l, int r, char ch) {
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        cnt += (str[i] != ch);
    }
    return cnt;
}

int good(string& str, int l, int r, char ch) {
    if (l == r) {
        return str[l] != ch;
    }
    int mid = l + r >> 1;
    int left = good(str, l, mid, ch + 1);
    int right = good(str, mid + 1, r, ch + 1);
    int x = count(str, mid + 1, r, ch) + left;
    int y = count(str, l, mid, ch) + right;
    return min(x, y);
}

void solve() {
    int n;
    string str;
    cin >> n >> str;
    cout << good(str, 0, n - 1, 'a') << endl;
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
