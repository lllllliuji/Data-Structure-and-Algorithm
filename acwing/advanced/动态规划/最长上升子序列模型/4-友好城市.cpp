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
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        nums.push_back(vec[i].second);
    }
    cout << solve(nums) << endl;
    return 0;
}