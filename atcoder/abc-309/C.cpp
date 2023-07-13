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
    int n, k;
    cin >> n >> k;
    using E = pair<int, int>;
    vector<E> vec;
    long long sum = 0;
    int d = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        d = max(d, a);
        sum += b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
    int i = 1;
    int j = 0;
    while (i <= d) {
        // cout << i << endl;
        while (j < n && vec[j].first < i) {
            sum -= vec[j].second;
            j++;
        }
        if (sum <= k) {
            break;
        }
        i = vec[j].first + 1;
    }
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
    solve();
    return 0;
}