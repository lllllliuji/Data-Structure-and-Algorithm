#include <iostream>
#include <vector>

using namespace std;

const int N = 2010;

long long arr[N];
long long f[N];
bool exist[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    exist[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            if (exist[j - 1]) {
                if (f[j - 1] + arr[i] >= 0) {
                    exist[j] = true;
                    f[j] = max(f[j], f[j - 1] + arr[i]);
                }
            }
        }
    }
    for (int i = n; i >= 0; i--) {
        if (exist[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}