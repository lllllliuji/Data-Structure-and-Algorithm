#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    long long k;
    cin >> k;
    string s = "codeforces";
    int n = s.size();
    vector<int> cnt(n, 1);

    long long times = 1;
    while (times < k) {
        long long t = times;
        for (int i = 0; i < n && t < k; i++) {
            t = t / cnt[i] * (cnt[i] + 1);
            cnt[i]++;
        }
        times = t;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}