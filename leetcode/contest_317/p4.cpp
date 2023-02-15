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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<TreeNode*, int> height;
        function<int(TreeNode*)> get_height = [&](TreeNode* node) {
            return node ? height[node] = max(get_height(node->left), get_height(node->right)) + 1 : 0;
        };
        get_height(root);
        vector<int> res(height.size() + 1);
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int depth, int rest_h) {
            if (!node) {
                return;
            }
            depth++;
            res[node->val] = rest_h;
            dfs(node->left, depth, max(rest_h, depth + height[node->right]));
            dfs(node->right, depth, max(rest_h, depth + height[node->left]));
        };
        dfs(root, -1, 0);
        vector<int> ans;
        for (int q : queries) {
            ans.push_back(res[q]);
        }
        return ans;
    }
};