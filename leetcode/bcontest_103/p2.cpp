class Solution {
   public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash[A[i]]++;
            unordered_map<int, int> f;
            for (int j = 0; j <= i; j++) {
                f[B[j]]++;
            }
            int cnt = 0;
            for (auto& [k, v] : hash) {
                cnt += min(f[k], v);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};