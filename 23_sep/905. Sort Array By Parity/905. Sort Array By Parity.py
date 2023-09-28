class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        ans = []
        for i in nums: 
            if i%2==0: 
                ans = [i] + ans
            else : 
                ans = ans + [i]

        return ans
