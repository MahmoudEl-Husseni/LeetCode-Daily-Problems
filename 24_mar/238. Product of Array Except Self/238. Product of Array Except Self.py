class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        suf = [0] * len(nums)
        pref = nums.copy()
        suf[n-1]=nums[n-1]
        
        for i in range(n-2, -1, -1) :
            suf[i] = suf[i+1] * nums[i]
        
        for i in range(1, n) :
            pref[i] *= pref[i-1]

        for i in range(n) :
            if i==0: 
                nums[i] = suf[i+1]
            elif i!=(n-1): 
                nums[i] = pref[i-1] * suf[i+1]
            else : 
                nums[i] = pref[i-1]
        return nums
            
            
