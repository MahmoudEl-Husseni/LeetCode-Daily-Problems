class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums = sorted(nums)
        sm=0
        for n in nums: 
            sm += n
            
        for n in nums[::-1]: 
            if n >= (sm-n) : 
                sm -= n
            else : 
                return sm
        return -1
