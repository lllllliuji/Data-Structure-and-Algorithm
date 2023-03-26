const int N = 100010;

int primes[N], cnt = 0;  // primes[]存储所有素数
// st[x]存储x是否被筛掉
bool st[N];
class Solution {
   public:
    void get_primes(int n) {
        if (cnt != 0) return;
        for (int i = 2; i <= n; i++) {
            if (!st[i]) primes[cnt++] = i;
            for (int j = 0; primes[j] <= n / i; j++) {
                st[primes[j] * i] = true;
                if (i % primes[j] == 0) break;
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        get_primes(1010);
        int n = nums.size();
        bool flag = true;
        for (int i = n - 2, x = nums[n - 1]; i >= 0; i--) {
            int mn;
            if (nums[i] < x) {
                x = nums[i];
                continue;
            }
            for (int j = 0; primes[j] < nums[i]; j++) {
                if (nums[i] - primes[j] < x) {
                    mn = nums[i] - primes[j];
                    break;
                }
            }
            nums[i] = mn;
            x = nums[i];
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) flag = false;
        }
        return flag;
    }
};