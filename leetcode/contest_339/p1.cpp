class Solution {
   public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int cnt = 0;
                int last = 0;
                bool flag = true;
                for (int k = j; k <= i; k++) {
                    if (s[k] == '0')
                        cnt--;
                    else
                        cnt++;
                    if ((s[k] - '0') < last) {
                        flag = false;
                        break;
                    }
                    last = max(last, s[k] - '0');
                }
                if (flag && (cnt == 0)) {
                    ans = max(ans, i - j + 1);
                }
            }
        }
        return ans;
    }
};