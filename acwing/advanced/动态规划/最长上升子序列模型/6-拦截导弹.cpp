#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x;
    vector<int> nums;
    while (cin >> x) nums.push_back(x);
    int n = nums.size();
    vector<int> f(n), g(n);
    int len = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        f[i] = g[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] <= nums[j])
                f[i] = max(f[i], f[j] + 1);
            else
                g[i] = max(g[i], g[j] + 1);
        }
        len = max(len, f[i]);
        cnt = max(cnt, g[i]);
    }
    cout << len << endl;
    cout << cnt << endl;
    return 0;
}