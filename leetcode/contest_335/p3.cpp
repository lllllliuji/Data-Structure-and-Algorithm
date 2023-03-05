class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, pair<int, int>> hash;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = 2; j <= x / j; j++) {
                if (x % j == 0) {
                    if (!hash.count(j)) {
                        hash[j] = {i, i};
                    } else {
                        hash[j].first = min(hash[j].first, i);
                        hash[j].second = max(hash[j].second, i);
                    }
                    while (x % j == 0) {
                        x /= j;
                    }
                }
            }
            if (x != 1) {
                if (!hash.count(x)) {
                    hash[x] = {i, i};
                } else {
                    hash[x].first = min(hash[x].first, i);
                    hash[x].second = max(hash[x].second, i);
                }
            }
        }
        vector<pair<int, int>> vec;
        for (auto&[k, v] : hash) vec.push_back(v);
        sort(vec.begin(), vec.end());
        for (int i = 0, m = vec.size(); i < m; i++) {
            int l = vec[i].first, r = vec[i].second;
            while (i + 1 < m && r >= vec[i + 1].first) {
                r = max(r, vec[i + 1].second);
                i++;
            }
            if (i < m - 1) {
                return r;
            } 
        }
        if (vec.size() == 0 && n > 1) return 0;
        return -1;
    }
};