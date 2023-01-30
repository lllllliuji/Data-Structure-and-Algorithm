class Solution {
   public:
    int get(int x) {
        int ans = 0;
        do {
            ans += x % 10;
            x /= 10;
        } while (x);
        return ans;
    }
    int differenceOfSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ss = 0;
        for (int num : nums) {
            ss += get(num);
        }
        return abs(sum - ss);
    }
};