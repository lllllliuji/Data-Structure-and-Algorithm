class Solution {
   public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int l = 0, r = price[n - 1] - price[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int cnt = 1, pre = 0;
            for (int i = 1; i < n; i++) {
                if (price[i] - price[pre] >= mid) {
                    cnt++;
                    pre = i;
                }
            }
            if (cnt >= k)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};