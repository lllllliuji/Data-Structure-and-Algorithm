/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> vec;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            vec.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        for (int x : vec) cout << x << " ";
        vector<vector<int>> ans;
        for (int q : queries) {
            auto low = lower_bound(vec.begin(), vec.end(), q);
            int l = -1, r = -1;
            if (low != vec.end()) {
                if (*low == q) {
                    l = *low;
                    r = *low;
                } else {
                    r = *low;
                    if (low != vec.begin()) {
                        l = *(low - 1);
                    }
                }
            } else {
                l = vec.back();
            }
            ans.push_back({l, r});
        }
        return ans;
    }
};