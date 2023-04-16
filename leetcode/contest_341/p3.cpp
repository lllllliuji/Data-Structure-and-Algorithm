class Solution {
   public:
    int addMinimum(string word) {
        int n = word.size();
        char pre = 'c';
        int ans = 0;
        for (char c : word) {
            if (c <= pre) ans += 3;
            pre = c;
        }
        return ans - n;
    }
};