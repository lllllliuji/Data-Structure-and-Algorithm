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
    long long f[100010];
    int max_depth;
    void dfs(TreeNode* node, int depth) {
        if (!node) {
            return;
        }
        max_depth = max(max_depth, depth);
        f[depth] += node->val;
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        max_depth = 0;
        memset(f, 0, sizeof f);
        dfs(root, 1);
        if (max_depth < k) {
            return -1;
        }
        sort(f + 1, f + max_depth + 1);
        return f[max_depth - k + 1];
    }
};