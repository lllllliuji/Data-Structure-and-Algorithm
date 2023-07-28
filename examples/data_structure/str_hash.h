#pragma once

#include <iostream>

using namespace std;

// 核心思想：将字符串看成P进制数，P的经验值是131或13331，取这两个值的冲突概率低
// 小技巧：取模的数用2^64，这样直接用unsigned long long存储，溢出的结果就是取模的结果
typedef unsigned long long ULL;
const int N = 100010;
const int P = 131;
ULL h[N], p[N];  // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64

void str_hash(string &str) {
    // 初始化
    p[0] = 1;
    for (int i = 0; i < str.size(); i++) {
        h[i + 1] = h[i] * P + str[i];
        p[i + 1] = p[i] * P;
    }
}

// 计算子串 str[l ~ r] 的哈希值
ULL get(int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; }