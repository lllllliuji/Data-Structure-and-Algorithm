class Solution {
   public:
    int cal(long long n) {
        int ans = 0;
        do {
            ans += n % 10;
            n /= 10;
        } while (n);
        return ans;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long ans = 0;
        for (int sum = cal(n); sum > target; sum = cal(n)) {
            long long base = 10;
            while ((n % base) == 0) {
                base *= 10;
            }
            ans += base - (n % base);
            n += base - (n % base);
        }
        return ans;
    }
};