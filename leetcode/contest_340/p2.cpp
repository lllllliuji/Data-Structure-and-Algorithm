class Solution {
   public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> v;
        unordered_map<int, vector<long long>> sum;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            v[nums[i]].push_back(i);
        }
        for (auto& [k, idxs] : v) {
            sum[k] = vector<long long>(idxs.size() + 1);
            for (int i = 0; i < idxs.size(); i++) {
                sum[k][i + 1] = sum[k][i] + idxs[i];
            }
        }
        vector<long long> ans;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int cnt = v[num].size();
            auto it = lower_bound(v[num].begin(), v[num].end(), i);
            int idx = it - v[num].begin();
            long long pre = 1LL * idx * i - sum[num][idx];
            long long suf = sum[num].back() - sum[num][idx] - 1LL * (cnt - idx) * i;
            ans.push_back(pre + suf);
        }
        return ans;
    }
};