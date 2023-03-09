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
    string str;
    cin >> str;
    bool flag = true;
    for (int i = str.size() - 1, x = 0; i >= 0; i--) {
        if (x == 0) {
            if (str[i] < '0' || str[i] > '9') x = 1;
        } else {
            if (str[i] >= '0' && str[i] <= '9') {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        int row = 0, col = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] < '0' || str[i] > '9') {
                col = col * 26 + (str[i] - 'A' + 1);
            } else {
                row = 10 * row + (str[i] - '0');
            }
        }
        cout << "R" << row << "C" << col << endl;
    } else {
        int pos = str.find("C");
        int row = 0, col = 0;
        row = stoi(str.substr(1, pos));
        col = stoi(str.substr(pos + 1));
        string t = "";
        while (col) {
            char c = (col % 26) == 0 ? 'Z' : 'A' + col % 26 - 1;
            t = c + t;
            col = col / 26 - (col % 26 == 0);
        }
        cout << t << row << endl;
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}