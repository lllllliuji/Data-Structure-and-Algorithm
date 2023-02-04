class Solution {
   public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        if (words[startIndex] == target) return 0;
        int ans = n;
        for (int i = (startIndex + 1) % n; i != startIndex; i = (i + 1) % n) {
            if (words[i] == target) {
                ans = min(ans, min((i - startIndex + n) % n, (startIndex - i + n) % n));
            }
        }
        return ans == n ? -1 : ans;
    }
};