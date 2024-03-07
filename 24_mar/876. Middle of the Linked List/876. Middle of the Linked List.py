# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = head
        n=0
        while node.next : 
            n+=1
            node = node.next
        
        node = head
        n=(n+1)//2
        while n : 
            n-=1
            node = node.next
            
        return node
        
