class Solution {
   public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int, vector<int>, less<int>> q;
        for (int g : gifts) {
            q.push(g);
        }
        while (k--) {
            auto t = q.top();
            q.pop();
            q.push(sqrt(t));
        }
        long long ans = 0;
        while (!q.empty()) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};