class Solution {
   public:
    bool makeStringsEqual(string s, string target) {
        if (s == target) return true;
        int n = s.size();
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            }
        }
        if (ones == 0) return false;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (target[i] == '1') cnt++;
        }
        if ('1' == target[n - 1]) return true;
        if (cnt > 0) return true;
        return false;
    }
};

// class Solution {
// public:
//     bool makeStringsEqual(string s, string target) {
//         return (s.find('1') == string::npos) == (target.find('1') == string::npos);
//     }
// };