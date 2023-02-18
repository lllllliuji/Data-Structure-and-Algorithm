#include <iostream>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> tree(n);
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i] >> height[i];
    }
    // 往左倒，往右倒，往右倒的距离
    vector<int> f(n), g(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            f[i] = 1;
            g[i] = (i == n - 1 ? 1 : (tree[i] + height[i] < tree[i + 1] ? 1 : 0));
            continue;
        }
        f[i] = max(f[i - 1] + (tree[i] - height[i] > tree[i - 1] ? 1 : 0),
                   g[i - 1] + (tree[i] - height[i] > tree[i - 1] + height[i - 1] ? 1 : 0));
        if (i < n - 1) {
            g[i] = max(f[i - 1], g[i - 1]) + (tree[i] + height[i] < tree[i + 1] ? 1 : 0);
        } else {
            g[i] = max(f[i - 1], g[i - 1]) + 1;
        }
        g[i] = max(f[i - 1], g[i - 1]) + (i == n - 1 ? 1 : (tree[i] + height[i] < tree[i + 1] ? 1 : 0));
    }
    cout << max(f[n - 1], g[n - 1]) << endl;
    return 0;
}