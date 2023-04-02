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

void tolower(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] = 'a' + (s[i] - 'A');
    }
}

void solve() {
    // 定义两个字符串
    string a;
    string b;
    // 用string库，调用getline, 直接读入一整行
    getline(cin, a);
    getline(cin, b);
    // 转换大小写，可以都转换为大写，或者小写
    for (int i = 0; i < a.length(); ++i) {
        a[i] = tolower(a[i]);
    }
    for (int i = 0; i < b.length(); ++i) {
        b[i] = tolower(b[i]);
    }
    // 因为连起来的不算，所以要在前后加几个空格，一定要是同样多的，同量减同量，等于同量
    a = ' ' + a + ' ';
    b = ' ' + b + ' ';
    // 先看看会不会找不到，用a.find()和string::npos
    if (b.find(a) == string::npos) {
        cout << -1 << endl;
    }
    // 如果找得到
    else {
        int alpha = b.find(a);
        int beta = b.find(a), s = 0;  // 计数器初始化为0
        while (beta != string::npos) {
            ++s;  // 计数器
            beta = b.find(a, beta + 1);
        }
        cout << s << " " << alpha << endl;  // 输出第一个和总共有几个
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