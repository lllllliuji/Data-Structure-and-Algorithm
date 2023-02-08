class Solution {
   public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string t;
        vector<string> vec;
        while (ss >> t) {
            vec.emplace_back(t);
        }
        int n = vec.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (vec[i].back() != vec[j].front()) return false;
        }
        return true;
    }
};