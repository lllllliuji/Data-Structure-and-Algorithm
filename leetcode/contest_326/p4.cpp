const int N = 1000010;
class Solution {
   public:
    int primes[N], cnt = 0;  // primes[]存储所有素数
    bool st[N];              // st[x]存储x是否被筛掉

    void get_primes(int n) {
        for (int i = 2; i <= n; i++) {
            if (!st[i]) primes[cnt++] = i;
            for (int j = 0; primes[j] <= n / i; j++) {
                st[primes[j] * i] = true;
                if (i % primes[j] == 0) break;
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        get_primes(right);
        int index = 0;
        while (index < cnt) {
            if (primes[index] >= left) break;
            index++;
        }
        if (cnt - index <= 1) {
            return {-1, -1};
        }
        // cout << index << " " << cnt << endl;
        int l = primes[index], r = primes[index + 1];
        for (int i = index; i + 1 < cnt; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < (r - l)) {
                l = primes[i];
                r = primes[i + 1];
            }
        }
        return {l, r};
    }
};