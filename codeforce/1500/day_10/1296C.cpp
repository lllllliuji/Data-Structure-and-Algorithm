#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int N = 200010;
char path[N];

void solve() {
    int n;
    cin >> n >> (path + 1);
    unordered_map<string, int> his;
    his["0_0"] = 0;
    int l = -1, r = -1;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (path[i] == 'L') {
            y = y - 1;
        } else if (path[i] == 'R') {
            y = y + 1;
        } else if (path[i] == 'U') {
            x = x - 1;
        } else {
            x = x + 1;
        }
        string t = to_string(x) + "_" + to_string(y);
        if (his.count(t)) {
            if (l == -1 && r == -1) {
                l = his[t] + 1;
                r = i;
            } else if (i - his[t] < r - l) {
                l = his[t] + 1;
                r = i;
            }
        }
        his[t] = i;
    }
    if (l != -1)
        cout << l << " " << r << endl;
    else
        cout << "-1" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}