class Solution {
   public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            if ((a & 1) && (b & 1) || !(a & 1) && !(b & 1)) {
                return a < b;
            }
            return (a & 1) == 1;
        });
        sort(target.begin(), target.end(), [](int a, int b) {
            if ((a & 1) && (b & 1) || !(a & 1) && !(b & 1)) {
                return a < b;
            }
            return (a & 1) == 1;
        });
        long long ans = 0;
        long long c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target[i]) {
                if (c < 0) {
                    ans += max((nums[i] - target[i]) + c, 0LL) / 2;
                    c += nums[i] - target[i];
                } else {
                    ans += abs(nums[i] - target[i]) / 2;
                    c += nums[i] - target[i];
                }
            } else if (nums[i] < target[i]) {
                if (c > 0) {
                    ans += abs(min(nums[i] - target[i] + c, 0LL)) / 2;
                    c += nums[i] - target[i];
                } else {
                    ans += abs(nums[i] - target[i]) / 2;
                    c += nums[i] - target[i];
                }
            }
            // cout << ans << endl;
        }
        return ans;
    }
};