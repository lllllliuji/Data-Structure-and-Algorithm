struct Node {
    long long w, rev;
};
struct SegTree {
    Node t[400005];
    void build(vector<int>& a, int u, int l, int r) {
        t[u].rev = 0;
        if (l == r) {
            t[u].w = a[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(a, u << 1, l, mid);
        build(a, u << 1 | 1, mid + 1, r);
        t[u].w = t[u << 1].w + t[u << 1 | 1].w;
    }
    void pushdown(int u, int l, int r) {
        if (!t[u].rev) return;
        int mid = (l + r) >> 1;
        t[u << 1].rev ^= 1;
        t[u << 1].w = (mid - l + 1) - t[u << 1].w;
        t[u << 1 | 1].rev ^= 1;
        t[u << 1 | 1].w = (r - mid) - t[u << 1 | 1].w;
        t[u].rev = 0;
    }
    void modify(int u, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            t[u].w = (r - l + 1) - t[u].w;
            t[u].rev ^= 1;
            return;
        }
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) modify(u << 1, l, mid, ql, qr);
        if (qr > mid) modify(u << 1 | 1, mid + 1, r, ql, qr);
        t[u].w = t[u << 1].w + t[u << 1 | 1].w;
    }
};
class Solution {
   public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        SegTree sgt;
        int n = nums1.size();
        sgt.build(nums1, 1, 1, n);
        long long sum = 0;
        for (int i : nums2) sum += i;
        vector<long long> ans;
        for (auto&& i : queries) {
            if (i[0] == 1)
                sgt.modify(1, 1, n, i[1] + 1, i[2] + 1);
            else if (i[0] == 2)
                sum += sgt.t[1].w * i[1];
            else
                ans.push_back(sum);
        }
        return ans;
    }
};