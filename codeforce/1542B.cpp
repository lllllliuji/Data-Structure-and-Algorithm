#include <algorithm>
#include <iostream>

using namespace std;

void solve(int m, int a, int b) {
    if (a == 1) {
        if (m % b == 1 || b == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
        return;
    }
    bool flag = false;
    for (long long i = 1; i <= m; i *= a) {
        if ((0LL + m - i) % b == 0) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int m, a, b;
        cin >> m >> a >> b;
        solve(m, a, b);
    }
    return 0;
}