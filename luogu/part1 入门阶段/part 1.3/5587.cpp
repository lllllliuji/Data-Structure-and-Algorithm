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
const int N = 1e4 + 5;
string s[N], t[N], s1;
long long n, m, cnt;
void solve() {
    while (getline(cin, s1), s1 != "EOF") {
        n++;  // 读入字符串
        for (char i : s1)
            if (i == '<') {
                if (!s[n].empty()) s[n].pop_back();
            }  // 模拟，如果是退格且string中还有字符就删掉一个
            else
                s[n].push_back(i);  // 否则加上去
    }
    while (getline(cin, s1), s1 != "EOF") {
        if (++m > n) break;
        for (char i : s1)
            if (i == '<') {
                if (!t[m].empty()) t[m].pop_back();
            } else
                t[m].push_back(i);                                                          // 同上
        for (int i = 0; i < min(t[m].size(), s[m].size()); i++) cnt += s[m][i] == t[m][i];  // 逐位比较
    }
    cin >> m;
    cout << (long long)(cnt * 60.0 / m + 0.5);  // 输出
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