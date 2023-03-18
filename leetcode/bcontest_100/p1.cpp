class Solution {
   public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        int avg = money / children;
        int x = money % children;
        if (avg == 8 && x == 0) {
            return children;
        }
        if (avg >= 8) {
            return children - 1;
        }
        int cnt = 0;
        for (int i = 0; i <= children; i++) {
            if (money - 8 >= children - i - 1) {
                money -= 8;
                cnt++;
            } else {
                break;
            }
        }
        if (cnt == children - 1 && (money % 8 == 4)) cnt--;
        return cnt;
    }
};