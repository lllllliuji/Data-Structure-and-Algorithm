class Solution {
   public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long l = 0, r = 1e18;
        while (l < r) {
            long long mid = l + r >> 1;
            long long total = 0;
            for (int i = 0; i < n; i++) {
                total += sqrt(mid / ranks[i]);
            }
            if (total >= cars)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};