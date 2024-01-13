def get_primes(n):
    # 欧拉线性筛素数
    # 说明：返回小于等于 n 的所有素数
    flag = [False] * (n + 1)
    primes = []
    for num in range(2, n + 1):
        if not flag[num]:
            primes.append(num)
        for prime in primes:
            if num * prime > n:
                break
            flag[num * prime] = True
            if num % prime == 0:
                break
    return primes