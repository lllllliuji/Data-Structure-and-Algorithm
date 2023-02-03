class Solution {
   public:
    int countDigits(int num) {
        string t = to_string(num);
        int ans = 0;
        for (char c : t) {
            int x = c - '0';
            if (num % x == 0) ans++;
        }
        return ans;
    }
};