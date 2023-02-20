#include <iostream>
#include <vector>

using namespace std;

int get(long long x) {
    int ans = 0;
    do {
        ans += x % 10;
        x /= 10;
    } while (x);
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;
        int cnt = get(n);
        long long base = 10;
        long long ans = 0;
        while (cnt > s) {
            ans += base - (n % base);
            n += base - (n % base);
            cnt = get(n);
            base *= 10;
        }
        cout << ans << endl;
    }
    return 0;
}