#include <math.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

const int N = 200010;

int n, k;
string s;
int p[N];
int sz[N][26];
int cnt[N];

void init() {
    for (int i = 0; i < n; i++) {
        p[i] = i;
        cnt[i] = 1;
        for (int j = 0; j < 26; j++) {
            sz[i][j] = 0;
        }
    }
}

int find(int x) { return x == p[x] ? p[x] : p[x] = find(p[x]); }

void unite(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) {
        p[fb] = fa;
        cnt[fa] += cnt[fb];
        for (int i = 0; i < 26; i++) {
            sz[fa][i] += sz[fb][i];
        }
    }
}

void solve() {
    cin >> n >> k >> s;
    init();
    for (int i = 0; i < n; i++) {
        sz[i][s[i] - 'a'] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (i + k < n) unite(i, i + k);
        if (n - i - 1 >= 0) unite(i, n - i - 1);
    }
    unordered_set<int> S;
    for (int i = 0; i < n; i++) {
        S.insert(find(i));
    }
    int ans = 0;
    for (int x : S) {
        int maxx = 0;
        for (int i = 0; i < 26; i++) {
            maxx = max(maxx, sz[x][i]);
        }
        ans += cnt[x] - maxx;
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}