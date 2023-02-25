#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int N = 200010;

int n, m;
int sz[N];
int p[N];
int edges[N];
int vis[N];
bool good[N];

void init() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
        edges[i] = 0;
        vis[i] = 0;
        good[i] = true;
    }
}

int find(int x) { return p[x] == x ? p[x] : p[x] = find(p[x]); }

void unite(int a, int b) {
    int fa = find(a), fb = find(b);
    vis[a]++;
    vis[b]++;
    if (vis[a] > 2 || vis[b] > 2) {
        good[fa] = false;
    }
    good[fa] &= good[fb];
    if (fa != fb) {
        p[fb] = fa;
        sz[fa] += sz[fb];
        edges[fa] += edges[fb] + 1;
    } else {
        edges[fa]++;
    }
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }
    unordered_set<int> roots;
    for (int i = 1; i <= n; i++) {
        roots.insert(find(i));
    }
    int ans = 0;
    for (int x : roots) {
        if (sz[x] >= 3 && sz[x] == edges[x] && good[x]) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}