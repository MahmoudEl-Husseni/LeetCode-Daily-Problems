# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        node = list1
        b+=2
        while node is not None : 
            a-=1
            b-=1
            if a==0: 
                cur = node
                while b: 
                    # print(b)
                    # print(node.val)
                    node = node.next
                    b-=1
                    
                cur.next = list2
                end = list2
                while end.next is not None: 
                    end = end.next
                    
                end.next = node
                
            node = node.next
            
        return list1
