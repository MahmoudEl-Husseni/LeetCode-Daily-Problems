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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q; 
        q.push(root);
        vector<int> vals;
        int lvl=0 ;
        int last = -1e9 ;
        while(!q.empty()){
            int k = q.size(); 
            for (int i=0;i<k;i++){

                TreeNode* node = q.front(); 
                q.pop();
                if (node->left)
                        q.push(node->left);
                if (node->right)
                        q.push(node->right); 

                
                if (lvl&1){
                    if ((node->val)&1 || node->val>=last) {
                        return false;
                    }
                    else {
                        last = node->val;
                    }
                }
                else {
                    if (node->val%2==0 || node->val<=last) {
                        return false;
                    }
                    else {
                        last = node->val;
                    }
                }
            }
            lvl += 1;
            last = ((lvl&1) ? 1e9 : -1e9);
        }
        return true;
    }
};
