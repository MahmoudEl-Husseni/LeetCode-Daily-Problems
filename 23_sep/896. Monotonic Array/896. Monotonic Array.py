class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        if len(nums)==1: return True
        i=1
        while nums[i]==nums[i-1] and i<len(nums)-1: 
            i+=1

        f = (nums[i] - nums[i-1]) > 0
        
        for i in range(i, len(nums)): 
            if(nums[i]==nums[i-1]): continue
            if ((nums[i] - nums[i-1]) > 0)!=f: 
                return False
        return True
