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
    int sol = INT_MIN;
    int dfs(TreeNode* root) {
        //try dfs
        if (!root) return 0;
        int left = 1+dfs(root->left);
        int right = 1+dfs(root->right);
        sol = max(sol,left+right);
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int trash = dfs(root);
        return sol-2;
    }
};
