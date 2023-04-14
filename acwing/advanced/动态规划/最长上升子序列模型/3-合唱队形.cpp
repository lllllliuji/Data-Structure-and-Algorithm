#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;

int nums[N];

int f[N];
int g[N];

void solve(vector<int> &nums, bool flag) {
    int n = nums.size();
    vector<int> q(n + 1);
    int len = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (q[mid] < nums[i])
                l = mid;
            else
                r = mid - 1;
        }
        q[l + 1] = nums[i];
        len = max(len, l + 1);
        if (flag)
            f[i] = len;
        else
            g[i] = len;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    solve(nums, true);
    reverse(nums.begin(), nums.end());
    solve(nums, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, f[i] + g[n - i - 1] - 1);
    }
    cout << n - ans << endl;
    return 0;
}