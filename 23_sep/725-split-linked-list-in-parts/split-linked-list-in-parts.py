# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        l = 0
        tmp = head
        while tmp: 
            l+=1
            tmp = tmp.next
        
        rm = l%k
        l = l // k
        ans = []
        tmp = head
        prev = head
        for i in range(k): 
            ans.append(tmp)
            for j in range(l+int(rm>0)):
                if tmp: 
                    prev = tmp
                    tmp = tmp.next
        
            if prev:
                prev.next = None
            rm-=1
        
        return ans