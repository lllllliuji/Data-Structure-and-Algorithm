#pragma once
/*
    f(n) 1~n中与n互质的数的个数
    f(6) = 2
    N = p1 ^ a1 * p2 ^ a2 ... * pk ^ ak
    f(n) = N * (1 - 1 / p1) * (1 - 1 / p2) *   (1 - 1 / pk)
*/

// 求1~x中与x互质的数的个数
int get_coprime(int x) {
    int ans = x;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            ans = ans / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ans = ans / x * (x - 1);
    return ans;
}

const int N = 1000010;

int primes[N], cnt;  // primes[]存储所有素数
int euler[N];        // 存储每个数的欧拉函数
bool st[N];          // st[x]存储x是否被筛掉

void get_eulers(int n) {
    euler[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0) {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}
