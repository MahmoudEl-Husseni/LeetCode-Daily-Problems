class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for w in words:
            f=1
            for i in range(len(w)//2): 
                if (w[i]!=w[len(w)-i-1]): 
                    f=0
                    break
            if f: 
                return w
        return ""
                
                
