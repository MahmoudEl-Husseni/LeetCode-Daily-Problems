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
    unordered_map<int, int> mp;
    void dfs(TreeNode* node){
        TreeNode* right = node->right; 
        TreeNode* left = node-> left;
        mp[node->val]++;
        if (right != NULL){
            dfs(right);
        }
        if (left != NULL){
            dfs(left);
        }
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        int freq=-1;
        vector<int> modes;
        for (auto [f, s]: mp){
            if (s>freq){
                modes = {f};
                freq=s;
            }
            else if (s==freq){
                modes.push_back(f);
            }
        }
        return modes;
    }
};
