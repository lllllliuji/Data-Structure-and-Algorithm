#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

string get(long long a, long long b, long long c) { return to_string(a) + "_" + to_string(b) + "_" + to_string(c); }

void solve() {
    long long a, b, c;
    unordered_map<string, int> f;

    using ll = long long;
    function<ll(ll, ll, ll)> w = [&](ll a, ll b, ll c) -> ll {
        // cout << a << " " << b << " " << c << endl;
        string t = get(a, b, c);
        if (f.count(t)) {
            return f[t];
        }
        if (a <= 0 || b <= 0 || c <= 0) {
            return f[t] = 1;
        }
        if (a > 20 || b > 20 || c > 20) {
            return f[t] = w(20, 20, 20);
        }
        if (a < b && b < c) {
            return f[t] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        }
        return f[t] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    };
    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
        // printf("w(%lld, %lld, %lld) = %lld\n", w(a, b, c));
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