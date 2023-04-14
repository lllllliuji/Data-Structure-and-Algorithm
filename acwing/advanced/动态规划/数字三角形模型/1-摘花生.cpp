#include <iostream>
#include <vector>
using namespace std;

const int N = 110;

int grid[N][N];
int f[N][N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> grid[i][j];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        cout << f[m][n] << endl;
    }
    return 0;
}