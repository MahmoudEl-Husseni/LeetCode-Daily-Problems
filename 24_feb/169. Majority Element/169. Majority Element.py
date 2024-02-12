class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        freq = dict()
        for n in nums: 
            if freq.get(n, 0)==0: 
                freq[n]=1
            else : 
                freq[n] += 1
        
        for k, v in freq.items(): 
            if v > len(nums)//2: 
                return k
