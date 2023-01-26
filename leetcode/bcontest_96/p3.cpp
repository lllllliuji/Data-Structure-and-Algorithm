class Solution {
   public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](const int& a, const int& b) { return nums2[a] > nums2[b]; });
        long long ans = 0;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int idx : idxs) {
            int x = nums1[idx];
            int y = nums2[idx];
            if (q.size() == k) {
                sum -= q.top();
                q.pop();
            }
            q.push(x);
            sum += x;
            if (q.size() == k) ans = max(ans, sum * y);
        }
        return ans;
    }
};