"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def __init__(self):
        self.vis = {}
    def copy(self, node: 'Node') -> 'Node':
        if not node: return None

        if node in self.vis: 
            return self.vis[node]

        tmp = Node(node.val)
        self.vis[node] = tmp
        
        tmp.next = self.copy(node.next)
        tmp.random = self.copy(node.random)

        return tmp

    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        return self.copy(head)