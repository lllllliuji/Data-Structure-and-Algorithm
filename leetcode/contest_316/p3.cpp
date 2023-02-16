// 二分
class Solution {
   public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int minn = *min_element(nums.begin(), nums.end());
        int maxx = *max_element(nums.begin(), nums.end());

        function<long long(int)> get = [&](int x) -> long long {
            long long res = 0;
            for (int i = 0; i < n; i++) {
                res += 1LL * abs(nums[i] - x) * cost[i];
            }
            return res;
        };

        int l = minn, r = maxx;
        while (l < r) {
            int mid = l + r >> 1;
            long long u = get(mid);
            long long v = get(mid + 1);
            if (u < v)
                r = mid;
            else
                l = mid + 1;
        }
        return get(l);
    }
};

// 三分求凸函数的最值
class Solution {
   public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int minn = *min_element(nums.begin(), nums.end());
        int maxx = *max_element(nums.begin(), nums.end());

        function<long long(int)> get = [&](int x) -> long long {
            long long res = 0;
            for (int i = 0; i < n; i++) {
                res += 1LL * abs(nums[i] - x) * cost[i];
            }
            return res;
        };

        int l = minn, r = maxx;
        while (l < r) {
            int delta = (r - l) / 3;
            int low = l + delta;
            int high = r - delta;
            if (get(low) < get(high))
                r = high - 1;
            else
                l = low + 1;
        }
        return get(l);
    }
};
