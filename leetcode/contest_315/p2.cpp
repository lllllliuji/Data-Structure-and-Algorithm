class Solution {
   public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<long> S(nums.begin(), nums.end());

        for (int num : nums) {
            string t = to_string(num);
            reverse(t.begin(), t.end());
            int x = stoi(t);
            S.insert(x);
            // cout << x << endl;
        }
        return S.size();
    }
};