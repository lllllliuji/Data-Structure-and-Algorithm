#include <math.h>

#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << (((int)sqrt(2 * n - 1) - 1)) / 2 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
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