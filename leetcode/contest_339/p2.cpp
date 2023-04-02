class Solution {
   public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> S(nums.begin(), nums.end());
        unordered_map<int, int> hash;
        for (int num : nums) hash[num]++;
        while (!S.empty()) {
            vector<int> d;
            vector<int> t;
            for (int x : S) {
                if (hash[x] > 0) {
                    t.push_back(x);
                    hash[x]--;
                }
                if (hash[x] == 0) {
                    d.push_back(x);
                }
            }
            ans.push_back(t);
            for (int u : d) {
                S.erase(u);
            }
        }
        return ans;
    }
};