#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int money, factor;
        cin >> money >> factor;
        arr.push_back({money, factor});
    }
    sort(arr.begin(), arr.end(), [](const auto& a, const auto &b) {
        return a.first < b.first;
    });
    vector<long long> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + arr[i].second;
    }
    long long ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (arr[i].first - arr[j].first >= m) {
            j ++;
        }
        ans = max(ans, sum[i + 1] - sum[j]);
    }
    cout << ans << endl;
    return 0;
}