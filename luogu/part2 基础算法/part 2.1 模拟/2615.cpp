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
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    matrix[0][n / 2] = 1;
    int row = 0, col = n / 2;
    for (int i = 2; i <= n * n; i++) {
        if (row == 0 && col != n - 1) {
            row = n - 1;
            col += 1;
        } else if (row != 0 && col == n - 1) {
            row -= 1;
            col = 0;
        } else if (row == 0 && col == n - 1) {
            row += 1;
        } else if (row != 0 && col != n - 1) {
            if (matrix[row - 1][col + 1] == 0) {
                row -= 1;
                col += 1;
            } else {
                row += 1;
            }
        }
        matrix[row][col] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
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
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}