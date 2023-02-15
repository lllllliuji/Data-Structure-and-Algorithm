class Solution {
   public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long> sum;
        unordered_map<string, int> top;

        int n = creators.size();
        long m_max = 0;
        for (int i = 0; i < n; i++) {
            sum[creators[i]] += views[i];
            m_max = max(sum[creators[i]], m_max);
            if (!top.count(creators[i])) {
                top[creators[i]] = i;
            } else if (views[i] > views[top[creators[i]]]) {
                top[creators[i]] = i;
            } else if (views[i] == views[top[creators[i]]] && ids[i] < ids[top[creators[i]]]) {
                top[creators[i]] = i;
            }
        }
        vector<vector<string>> ans;
        for (auto& [k, v] : top) {
            if (sum[k] == m_max) ans.push_back({k, ids[v]});
        }
        return ans;
    }
};