#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> refactor(int num) {
    vector<pair<int, int>> ans;
    for (int i = 2; i <= num / i; i++) {
        if (num % i == 0) {
            int cnt = 0;
            while (num % i == 0) {
                num /= i;
                cnt++;
            }
            ans.emplace_back(i, cnt);
        }
    }
    return ans;
}

vector<int> get_factor(int num) {
    auto res = refactor(num);
    vector<int> ans;
    for (auto& item : res) {
        ans.emplace_back(item.first);
    }
    return ans;
}