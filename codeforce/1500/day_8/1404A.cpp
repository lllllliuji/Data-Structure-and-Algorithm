#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    string str;
    cin >> n >> k >> str;
    for (int i = 0; i < k; i++) {
        if (str[i] == '?') {
            for (int j = i + k; j < n; j += k) {
                if (str[j] != '?') {
                    str[i] = str[j];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        if (str[i] != '?') {
            for (int j = i + k; j < n; j += k) {
                if (str[j] == '?') {
                    str[j] = str[i];
                } else if (str[i] != str[j]) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    int zeros = 0, ones = 0;
    for (int i = 0; i < k; i++) {
        if (str[i] == '0') zeros++;
        if (str[i] == '1') ones++;
    }
    if (max(zeros, ones) > k / 2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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