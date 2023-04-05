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
long long fp[10'000'000];

void solve() {
    int m;
    cin >> m;
    function<long long(long long)> find = [&](long long i) -> long long {
        if (fp[i]) return fp[i];
        if (i == 1 || i == 2) return fp[i] = 1 % m;
        return fp[i] = (fp[i - 1] + fp[i - 2]) % m;
    };
    int i = 1;
    while (find(i) != 0 || find(i + 1) != 1) i++;
    cout << i << endl;
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