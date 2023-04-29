class Solution {
   public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
            if (i >= k) {
                hash[nums[i - k]]--;
            }
            if (i < k - 1) continue;
            bool flag = false;
            int cnt = 0;
            int j;
            for (j = -50; j < 0; j++) {
                cnt += hash[j];
                if (cnt >= x) break;
            }
            if (cnt >= x) {
                ans.push_back(j);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};