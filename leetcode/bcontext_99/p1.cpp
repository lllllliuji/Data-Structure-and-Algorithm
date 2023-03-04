class Solution {
   public:
    int splitNum(int num) {
        int cnt[10];
        string t = to_string(num);
        memset(cnt, 0, sizeof cnt);
        for (char c : t) {
            cnt[c - '0']++;
        }
        string num1, num2;
        int op = 0;
        for (int i = 1; i <= 9; i++) {
            while (cnt[i] > 0) {
                if (op == 0) {
                    num1.push_back('0' + i);
                } else {
                    num2.push_back('0' + i);
                }
                op = 1 - op;
                cnt[i]--;
            }
        }
        int ans = 0;
        if (num1.size()) {
            ans += stoi(num1);
        }
        if (num2.size()) {
            ans += stoi(num2);
        }
        return ans;
    }
};