#include <iostream>

using namespace std;

const int N = 15;

int f[2 * N][N][N];
int grid[N][N];

int main() {
    int n;
    cin >> n;
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        grid[a][b] = c;
    }
    for (int k = 2; k <= 2 * n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int u = 1; u <= n; u++) {
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
    cout << f[2 * n][n][n];
    return 0;
}