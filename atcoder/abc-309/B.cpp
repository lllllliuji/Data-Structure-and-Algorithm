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
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j] = s[j] - '0';
        }
    }

    int i = 0, j = 0;
    int tmp = g[i][j];
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int dir = 0;
    while (true) {
        int a = i + dx[dir], b = j + dy[dir];
        if (a == -1 || b == -1 || a == n || b == n) {
            dir = (dir + 1) % 4;
            a = i + dx[dir];
            b = j + dy[dir];
        }
        // cout << a << " " << b << endl;
        if (vis[a][b]) {
            break;
        }
        swap(g[a][b], tmp);
        vis[a][b] = true;
        i = a;
        j = b;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j];
        }
        cout << endl;
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
    solve();
    return 0;
}