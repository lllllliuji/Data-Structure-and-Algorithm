class Solution {
   public:
    int passThePillow(int n, int time) {
        int pos = 1;
        int x = 1;
        while (time--) {
            pos = pos + x;
            if (pos == n + 1) {
                pos = n - 1;
                x = -x;
            }
            if (pos == 0) {
                pos = 2;
                x = -x;
            }
        }
        return pos;
    }
};