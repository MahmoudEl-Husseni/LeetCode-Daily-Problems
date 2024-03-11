class Solution:
    def customSortString(self, order: str, s: str) -> str:
        freq1 = [0] * 26
        ans, alpha = "", 'abcdefghijklmnopqrstuvwxyz'
        for c in s: 
            freq1[ord(c) - ord('a')] += 1
        
        for c in order: 
            for j in range(freq1[ord(c) - ord('a')]) : 
                ans += c
                freq1[ord(c) - ord('a')] -= 1
        
        for j in range(26) : 
            for k in range(freq1[j]) : 
                ans += alpha[j]
                
        return ans
