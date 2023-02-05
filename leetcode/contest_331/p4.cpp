class Solution {
   public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> hash;
        for (int x : basket1) hash[x]++;
        for (int x : basket2) hash[x]--;
        vector<int> v1, v2;
        for (auto& [k, v] : hash) {
            if (v % 2 != 0) return -1;
            if (v > 0) {
                for (int i = 0; i < v / 2; i++) v1.push_back(k);
            }
            if (v < 0) {
                for (int i = 0; i < (-v / 2); i++) v2.push_back(k);
            }
        }
        int minV1 = *min_element(basket1.begin(), basket1.end());
        int minV2 = *min_element(basket2.begin(), basket2.end());
        int minVal = min(minV1, minV2);
        reverse(v2.begin(), v2.end());
        long long ans = 0;
        for (int i = 0; i < v1.size(); i++) {
            ans += min({v1[i], v2[i], 2 * minVal});
        }
        return ans;
    }
};