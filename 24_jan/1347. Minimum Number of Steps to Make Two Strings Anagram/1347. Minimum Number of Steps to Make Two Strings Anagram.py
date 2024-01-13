class Solution:
    def minSteps(self, s: str, t: str) -> int:
        fs = [0] * 26
        ff = [0] * 26
        for c in s:
            fs[ord(c)-ord('a')]+=1
        
        for c in t: 
            ff[ord(c)-ord('a')]+=1
        
        ans=0
        for i in range(26): 
            if (fs[i]>ff[i]): ans+=(fs[i]-ff[i])

        return ans
