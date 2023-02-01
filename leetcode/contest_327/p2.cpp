class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int, vector<int>, less<int>> q;
        for (int num : nums) {
            q.push(num);
        }
        while (k--) {
            int t = q.top();
            q.pop();
            ans += t;
            q.push((t + 2) / 3);
        }
        return ans;
    }
};