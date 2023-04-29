int t[100010];
class Solution {
   public:
    int n;
    int lowbit(int x) { return x & -x; }
    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) t[i] += c;
    }
    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans += t[i];
        return ans;
    }
    long long countOperationsToEmptyArray(vector<int>& nums) {
        n = nums.size();
        for (int i = 1; i <= n; i++) t[i] = 0;
        using E = pair<int, int>;
        vector<E> vec;
        for (int i = 0; i < n; i++) vec.push_back({nums[i], i + 1});
        sort(vec.begin(), vec.end());
        int now = 0;
        long long ans = 0;
        for (auto [num, idx] : vec) {
            if (idx < now) {
                ans += n - now;
                ans -= query(n) - query(now);
                now = 0;
            }
            ans += idx - now;
            ans -= query(idx) - query(now);
            add(idx, 1);
            now = idx;
        }
        return ans;
    }
};