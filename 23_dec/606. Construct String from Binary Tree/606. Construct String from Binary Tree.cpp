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
    string ans = "";
    string num(int num){
        string ret = "";
        bool f = num<0;
        num = abs(num); 
        if (num==0) return "0";
        while(num){
            ret += '0' + num%10;
            num/=10;
        }
        if (f) ret+='-';
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void dfs(TreeNode* node){
        ans += num(node->val);
        bool f=0;
        if (node->left){
            ans += '(';
            dfs(node->left);
            ans += ')';
            f=1;
        }
        if (node->right){
            if (!f) ans +="()";
            ans += '(';
            dfs(node->right);
            ans += ')';
        }
    }
    string tree2str(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
