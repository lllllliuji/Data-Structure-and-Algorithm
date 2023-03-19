class Solution {
   public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            nums[i] = (nums[i] % value + value) % value;
            cnt[nums[i]]++;
        }
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[x % value] != 0) {
                cnt[x % value]--;
                x++;
            } else {
                break;
            }
        }
        return x;
    }
};