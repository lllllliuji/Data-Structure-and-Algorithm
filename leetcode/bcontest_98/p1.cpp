class Solution {
   public:
    int minMaxDifference(int num) {
        string t = to_string(num);
        int maxx = 0, minn = num;

        for (char c = '0'; c <= '9'; c++) {
            string x = t;
            for (char u = '0'; u <= '9'; u++) {
                string x = t;
                for (int j = 0; j < x.size(); j++) {
                    if (x[j] == c) x[j] = u;
                }
                int v = stoi(x);
                maxx = max(maxx, v);
                minn = min(minn, v);
            }
        }
        return maxx - minn;
    }
};