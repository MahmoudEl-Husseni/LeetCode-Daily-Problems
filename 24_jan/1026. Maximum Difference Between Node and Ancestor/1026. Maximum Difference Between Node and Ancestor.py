# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node, mx, mn): 
        mx = max(node.val, mx)
        mn = min(node.val, mn)
        self.ans=max(self.ans, mx-mn)
        if node.right is not None: 
            self.dfs(node.right, mx, mn)

        if node.left is not None: 
            self.dfs(node.left, mx, mn)
            
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        self.ans = 0 
        self.dfs(root, 0, 1e9)
        return self.ans
