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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> nums;
            while (n--) {
                auto t = q.front();
                q.pop();
                nums.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            vector<int> idxs(nums.size());
            iota(idxs.begin(), idxs.end(), 0);
            sort(idxs.begin(), idxs.end(), [&](int a, int b) { return nums[a] < nums[b]; });
            for (int i = 0; i < idxs.size(); i++) {
                int u = i;
                while (u != idxs[u]) {
                    swap(idxs[u], idxs[idxs[u]]);
                    ans++;
                }
            }
        }
        return ans;
    }
};