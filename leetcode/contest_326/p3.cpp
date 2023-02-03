class Solution {
   public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        bool flag = true;

        int i = 0, j = 0;
        int cnt = 0;
        while (i < n) {
            if ((s[i] - '0') > k) {
                flag = false;
                break;
            }
            while (i + 1 < n && (10LL * stoi(s.substr(j, i - j + 1)) + (s[i + 1] - '0')) <= k) i++;
            cnt++;
            i++;
            j = i;
        }
        return flag ? cnt : -1;
    }
};