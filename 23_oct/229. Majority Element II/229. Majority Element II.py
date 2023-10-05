class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        freq = dict()
        for n in nums: 
            if freq.get(n, -1)==-1:
                freq[n]=0
            freq[n]+=1
        
        ans = []
        for k, v in freq.items(): 
            if v>len(nums)//3: 
                ans.append(k)
        return ans
