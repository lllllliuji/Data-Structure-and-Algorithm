#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> q(n + 1);
    int len = 0;
    for (int num : nums) {
        int l = 0, r = len;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (q[mid] < num)
                l = mid;
            else
                r = mid - 1;
        }
        q[l + 1] = num;
        len = max(len, l + 1);
    }
    return len;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> f(n);
        for (int i = 0; i < n; i++) cin >> f[i];
        int a = solve(f);
        reverse(f.begin(), f.end());
        int b = solve(f);
        cout << max(a, b) << endl;
    }
    return 0;
}