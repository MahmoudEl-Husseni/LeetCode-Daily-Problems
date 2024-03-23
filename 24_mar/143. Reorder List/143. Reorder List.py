# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        head.prev = None
        node = head.next
        if node is None: 
            return 
        while node.next is not None : 
            node.next.prev = node
            node = node.next
        
        front, back = head, node
        while front != back and front.next!=back:

            fnxt = front.next
            bprev = back.prev
            
            front.next = back
            back.prev = front
            back.next = fnxt
            
            front = fnxt
            back = bprev
        back.next = None
