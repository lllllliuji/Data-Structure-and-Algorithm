#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<vector<long long>> f(2, vector<long long>(4));
    f[0][3] = 1;
    int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j != k) {
                    f[1][j] += f[0][k];
                }
            }
            f[1][j] %= mod;
        }
        for (int j = 0; j < 4; j++) {
            f[0][j] = f[1][j];
            f[1][j] = 0;
        }
    }
    cout << f[0][3] << endl;
    return 0;
}