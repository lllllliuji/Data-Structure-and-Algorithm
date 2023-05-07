class Solution {
   public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> x(n);
        unordered_set<int> s;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            x[i] = s.size();
            s.insert(nums[i]);
        }
        s.clear();
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
            ans.push_back((int)s.size() - x[i]);
        }
        return ans;
    }
};