class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        it=0
        for n in nums : 
            if n>0 : 
                ans[it]=n
                it+=2
        it=1
        for n in nums : 
            if n<0 : 
                ans[it]=n
                it+=2
        return ans
