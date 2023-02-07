class Allocator {
   public:
    int n;
    set<pair<int, int>> S;
    unordered_map<int, vector<pair<int, int>>> his;
    Allocator(int n_) {
        n = n_;
        S.insert({0, n - 1});
    }

    int allocate(int size, int mID) {
        auto it = S.begin();
        for (; it != S.end(); it++) {
            if (it->second - it->first + 1 >= size) {
                break;
            }
        }
        if (it != S.end()) {
            int a = it->first, b = it->second;
            his[mID].emplace_back(it->first, it->first + size - 1);
            S.erase(it);
            if (a + size <= b) {
                S.insert({a + size, b});
            }
            return a;
        }
        return -1;
    }

    int free(int mID) {
        if (!his.count(mID)) {
            return 0;
        }
        int ans = 0;
        for (auto& item : his[mID]) {
            ans += item.second - item.first + 1;
            S.insert({item.first, item.second});
        }
        his.erase(mID);
        vector<pair<int, int>> vec;
        for (auto it = S.begin(); it != S.end(); it++) {
            vec.emplace_back(it->first, it->second);
        }
        S.clear();
        for (int i = 0, n = vec.size(); i < n;) {
            int k = i;
            int left = vec[i].first;
            int right = vec[i].second;
            while (k + 1 < n && vec[k + 1].first <= right + 1) {
                right = max(right, vec[k + 1].second);
                k++;
            }
            S.insert({left, right});
            i = k + 1;
        }
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */