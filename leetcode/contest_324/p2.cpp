const int N = 100010;
class Solution {
   public:
    int primes[N], cnt;  // primes[]存储所有素数
    bool st[N];          // st[x]存储x是否被筛掉

    void get_primes(int n) {
        for (int i = 2; i <= n; i++) {
            if (!st[i]) primes[cnt++] = i;
            for (int j = 0; primes[j] <= n / i; j++) {
                st[primes[j] * i] = true;
                if (i % primes[j] == 0) break;
            }
        }
    }

    int smallestValue(int n) {
        get_primes(n);
        int ans = INT_MAX;
        unordered_set<int> s;
        s.insert(n);
        while (st[n]) {
            int sum = 0;
            for (int i = 2; i <= n; i++) {
                if (n % i == 0) {
                    while (n % i == 0) {
                        n /= i;
                        sum += i;
                    }
                }
            }
            if (n != 1) sum += n;
            n = sum;
            ans = min(ans, sum);
            if (s.count(n)) break;
            s.insert(n);
        }
        ans = min(ans, n);
        return ans;
    }
};