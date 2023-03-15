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

void solve() {
    string t;
    cin >> t;
    int num = 0;
    int idx = 1;
    for (char c : t) {
        if (c >= '0' && c <= '9' && idx < 10) {
            num += (c - '0') * idx;
            idx++;
        }
    }
    num = num % 11;
    if (num == 10 && t.back() == 'X' || (('0' + num) == t.back())) {
        cout << "Right" << endl;
    } else {
        t.back() = num == 10 ? 'X' : ('0' + num);
        cout << t << endl;
    }
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