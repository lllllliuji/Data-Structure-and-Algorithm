class Solution {
   public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int m = n / 2;
        long long sum = accumulate(skill.begin(), skill.end(), 0LL);
        if (sum % m) {
            return -1;
        }
        sort(skill.begin(), skill.end());
        int total = sum / m;
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            if (skill[i] + skill[n - i - 1] != total) return -1;
            ans += skill[i] * skill[n - i - 1];
        }
        return ans;
    }
};