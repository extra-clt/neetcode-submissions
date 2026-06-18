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
    int goodNodes(TreeNode* root) {
        //dfs with max store per path
        int cnt = 1;
        stack<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.top(); q.pop();
            if (node->left) {
                q.push(node->left);
                if (node->left->val >= node->val) {
                    cnt++;
                }
                else {
                    node->left->val = node->val;
                }
            }
            if (node->right) {
                q.push(node->right);
                if (node->right->val >= node->val) {
                    cnt++;
                }
                else {
                    node->right->val = node->val;
                }
            }
        }
        return cnt;
    }
                
};
