#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> f(n + 1);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        f[i] = nums[i];
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + nums[i]);
        }
        ans = max(ans, f[i]);
    }

    cout << ans << endl;
    return 0;
}