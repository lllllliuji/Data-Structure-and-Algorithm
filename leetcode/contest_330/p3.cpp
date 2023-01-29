class Solution {
   public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> b;
        for (int i = 0; i < n - 1; i++) {
            b.push_back(weights[i] + weights[i + 1]);
        }
        sort(b.begin(), b.end());
        long long m = 0, M = 0;
        for (int i = 0, sz = b.size(); i < k - 1; i++) {
            m += b[i];
            M += b[sz - i - 1];
        }
        return M - m;
    }
};