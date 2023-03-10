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
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 0;
    int sx, sy;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '.') {
                cnt++;
                sx = i;
                sy = j;
            }
        }
    }
    cnt -= k;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    function<void(int x, int y)> dfs = [&](int x, int y) {
        if (cnt <= 0) {
            return;
        }
        grid[x][y] = 'X';
        cnt--;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == '.') {
                dfs(a, b);
            }
        }
    };
    dfs(sx, sy);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.')
                grid[i][j] = 'X';
            else if (grid[i][j] == 'X')
                grid[i][j] = '.';
        }
        cout << grid[i] << endl;
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