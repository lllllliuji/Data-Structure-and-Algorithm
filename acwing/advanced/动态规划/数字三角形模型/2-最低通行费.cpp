#include <iostream>

using namespace std;

const int N = 110;
int grid[N][N];
int f[N][N];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i <= n; i++) f[i][0] = f[0][i] = 0x3f3f3f3f;
    f[1][1] = grid[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
        }
    }
    cout << f[n][n] << endl;
    return 0;
}