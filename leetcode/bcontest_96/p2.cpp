class Solution {
   public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) {
            for (int i = 0; i < nums1.size(); i++) {
                if (nums1[i] != nums2[i]) return -1;
            }
            return 0;
        }
        int n = nums1.size();
        vector<int> diff(n);
        long long a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            diff[i] = nums1[i] - nums2[i];
            if (diff[i] % k != 0) return -1;
            diff[i] /= k;
            if (diff[i] < 0)
                a += -diff[i];
            else
                b += diff[i];
        }
        if (a != b) return -1;
        return a;
    }
};