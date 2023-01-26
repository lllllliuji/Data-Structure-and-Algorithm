class Solution {
   public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> S(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int num : nums2) {
            if (S.count(num)) return num;
        }
        return -1;
    }
};