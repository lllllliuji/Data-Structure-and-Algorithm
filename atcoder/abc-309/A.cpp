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
    int a, b;
    cin >> a >> b;
    if (a == 3 || a == 6 || a == 9) {
        cout << "No" << endl;
        return;
    }
    if (a == b - 1) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout << setprecision(10) << fixed;
    solve();
    return 0;
}