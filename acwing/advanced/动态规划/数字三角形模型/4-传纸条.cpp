#include <iostream>

using namespace std;

const int N = 55;

int grid[N][N];
int f[2 * N][N][N];

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int k = 2; k <= m + n; k++) {
        for (int i = 1; i <= m; i++) {
            for (int u = 1; u <= m; u++) {
                int j = k - i, v = k - u;
                if (j >= 1 && j <= n && v >= 1 && v <= n) {
                    int w = grid[i][j];
                    if (i != u) w += grid[u][v];
                    f[k][i][u] = max(f[k][i][u], f[k - 1][i][u] + w);
                    f[k][i][u] = max(f[k][i][u], f[k - 1][i - 1][u] + w);
                    f[k][i][u] = max(f[k][i][u], f[k - 1][i][u - 1] + w);
                    f[k][i][u] = max(f[k][i][u], f[k - 1][i - 1][u - 1] + w);
                }
            }
        }
    }
    cout << f[m + n][m][m];
    return 0;
}