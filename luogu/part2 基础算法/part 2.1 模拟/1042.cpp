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

void solve() {
    string str;
    int a = 0, b = 0;
    int c = 0, d = 0;
    vector<pair<int, int>> match_record_11;
    vector<pair<int, int>> match_record_21;
    while (cin >> str) {
        for (char ch : str) {
            if (ch == 'E') {
                for (auto& [a, b] : match_record_11) {
                    cout << a << ":" << b << endl;
                }
                cout << a << ":" << b << endl;
                cout << endl;
                for (auto& [a, b] : match_record_21) {
                    cout << a << ":" << b << endl;
                }
                cout << c << ":" << d << endl;
                return;
            }
            if (ch == 'W') {
                a += 1;
                c += 1;
            } else {
                b += 1;
                d += 1;
            }
            if ((a >= 11 || b >= 11) && abs(a - b) >= 2) {
                match_record_11.push_back({a, b});
                a = b = 0;
            }
            if ((c >= 21 || d >= 21) && abs(c - d) >= 2) {
                match_record_21.push_back({c, d});
                c = d = 0;
            }
        }
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