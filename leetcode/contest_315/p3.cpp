class Solution {
   public:
    bool check(int u, int v) {
        string x = to_string(u);
        string y = to_string(v);
        while (!y.empty() && y.back() == '0') y.pop_back();
        reverse(y.begin(), y.end());
        return x == y;
    }
    bool sumOfNumberAndReverse(int num) {
        if (num == 0) return true;
        for (int i = 1; i <= num / 2; i++) {
            int u = i, v = num - i;
            if (check(u, v)) {
                return true;
            }
        }
        return false;
    }
};