#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int cnt[N];
int main() {
    freopen("input.txt", "r", stdin);
    int n, v, maxn = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        cnt[v]++;
        maxn = max(maxn, v);
    }
    long long f[maxn + 1];
    memset(f, 0, sizeof f);
    long long ans = 0;
    for (int i = 1; i <= maxn; i++) {
        f[i + 1] = f[i];
        f[i + 1] = max(f[i + 1], f[i - 1] + 1LL * i * cnt[i]);
        ans = max(ans, f[i + 1]);
    }
    cout << ans << endl;
    return 0;
}