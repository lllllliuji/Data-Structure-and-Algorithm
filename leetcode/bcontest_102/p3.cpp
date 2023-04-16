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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> hash;
        unordered_map<TreeNode*, int> sons;
        unordered_map<TreeNode*, int> height;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int depth) {
            if (!node) {
                return;
            }
            hash[depth] += node->val;
            height[node] = depth;
            if (node->left) sons[node] += node->left->val;
            if (node->right) sons[node] += node->right->val;
            dfs(node->left, depth + 1);
            dfs(node->right, depth + 1);
        };
        dfs(root, 0);
        root->val = 0;
        for (auto& [node, sum] : sons) {
            if (node->left) {
                node->left->val = hash[height[node->left]] - sum;
            }
            if (node->right) {
                node->right->val = hash[height[node->right]] - sum;
            }
        }
        return root;
    }
};