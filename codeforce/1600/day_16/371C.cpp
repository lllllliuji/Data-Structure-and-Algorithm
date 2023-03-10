#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int na, nb, nc;
    int pa, pb, pc;
    long long balance;
    string str;
    cin >> str;
    cin >> na >> nb >> nc;
    cin >> pa >> pb >> pc;
    cin >> balance;
    int a, b, c;
    a = b = c = 0;
    for (char ch : str) {
        if (ch == 'B')
            a++;
        else if (ch == 'S')
            b++;
        else
            c++;
    }
    int cost = a * pa + b * pb + c * pc;
    function<bool(long long)> check = [&](long long x) -> bool {
        if (balance / cost >= x) return true;
        long long totala = x * a, totalb = x * b, totalc = x * c;
        long long diffa = na - totala > 0 ? 0 : totala - na;
        long long diffb = nb - totalb > 0 ? 0 : totalb - nb;
        long long diffc = nc - totalc > 0 ? 0 : totalc - nc;
        return balance >= diffa * pa + diffb * pb + diffc * pc;
    };

    long long l = 0, r = (balance + na * pa + nb * pb + nc * pc) / cost;
    while (l < r) {
        long long mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}