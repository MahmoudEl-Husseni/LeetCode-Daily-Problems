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
    int ans = 0;
    pair<int, int> dfs(TreeNode* node){
        int val = node->val;
        int n=1;
        if(node->left){
            pair<int, int> p = dfs(node->left);
            val += p.first;
            n += p.second;
        }
        if (node->right){
            pair<int, int> p = dfs(node->right);
            val += p.first;
            n += p.second;
        }
        if ((val / n) == node->val)
            ans++;
        return {val, n};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
