class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        freq = dict()
        
        for n in arr : 
            if freq.get(n, 0)==0 : 
                freq[n]=0
            freq[n] += 1
        freq = list(sorted(freq.items(), key = lambda x : x[1]))
        i = 0 
        while k > 0 : 
            if k >= freq[i][1] : 
                k -= freq[i][1]
                i+=1
            else : 
                break
                
        return len(freq) - i
