class Solution {
   public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0;; i++) {
            int cnt = 0;
            unordered_set<int> S;
            int x = i;
            while (x) {
                S.insert(x % 10);
                x /= 10;
            }
            bool flag = false;
            for (int num : nums1) {
                while (num) {
                    if (S.count(num % 10)) {
                        cnt++;
                        flag = true;
                        break;
                    }
                    num /= 10;
                }
                if (flag) break;
            }
            flag = false;
            for (int num : nums2) {
                while (num) {
                    if (S.count(num % 10)) {
                        cnt++;
                        flag = true;
                        break;
                    }
                    num /= 10;
                }
                if (flag) break;
            }
            if (cnt == 2) {
                return i;
            }
        }
        return 0;
    }
};