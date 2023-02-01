class Solution {
   public:
    int findCrossingTime(int n, int k, vector<vector<int>> &time) {
        stable_sort(time.begin(), time.end(), [](auto &a, auto &b) { return a[0] + a[2] < b[0] + b[2]; });
        priority_queue<pair<int, int>> waitL, waitR;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> workL, workR;
        for (int i = k - 1; i >= 0; --i) waitL.emplace(i, 0);  // 下标越大效率越低
        int cur = 0;
        while (n) {
            while (!workL.empty() && workL.top().first <= cur) {
                auto [t, i] = workL.top();
                workL.pop();
                waitL.emplace(i, t);  // 左边完成放箱
            }
            while (!workR.empty() && workR.top().first <= cur) {
                auto [t, i] = workR.top();
                workR.pop();
                waitR.emplace(i, t);  // 右边完成搬箱
            }
            if (!waitR.empty()) {  // 右边过桥，注意加到 waitR 中的都是 <= cur 的（下同）
                auto [i, t] = waitR.top();
                waitR.pop();
                cur += time[i][2];
                workL.emplace(cur + time[i][3], i);  // 放箱
            } else if (!waitL.empty()) {             // 左边过桥
                auto [i, t] = waitL.top();
                waitL.pop();
                cur += time[i][0];
                workR.emplace(cur + time[i][1], i);  // 搬箱
                --n;
            } else if (workL.empty())
                cur = workR.top().first;  // cur 过小，找个最小的放箱/搬箱完成时间来更新 cur
            else if (workR.empty())
                cur = workL.top().first;
            else
                cur = min(workL.top().first, workR.top().first);
        }
        while (!workR.empty()) {
            auto [t, i] = workR.top();  // 右边完成搬箱
            workR.pop();
            // 如果没有排队，直接过桥；否则由于无论谁先过桥，最终完成时间都一样，所以也可以直接计算
            cur = max(t, cur) + time[i][2];
        }
        return cur;  // 最后一个过桥的时间
    }
};