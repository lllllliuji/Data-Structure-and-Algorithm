class Solution {
   public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) diff[i] = i;
        sort(diff.begin(), diff.end(), [&](int a, int b) { return reward1[a] - reward2[a] > reward1[b] - reward2[b]; });
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < k)
                ans += reward1[diff[i]];
            else
                ans += reward2[diff[i]];
        }
        return ans;
    }
};