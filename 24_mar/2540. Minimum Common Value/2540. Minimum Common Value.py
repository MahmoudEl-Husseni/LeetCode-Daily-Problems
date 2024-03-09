class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        f1, f2 = dict(), dict()
        for i in nums1: 
            if f1.get(i, 0)==0: 
                f1[i]=0
            f1[i]+=1
        
        for i in nums2: 
            if f2.get(i, 0)==0: 
                f2[i]=0
            f2[i]+=1
        
        f1 = sorted(f1.items(), key=lambda x : x[0])
        
        for k, v in f1: 
            if f2.get(k, 0)>0: 
                return k
        return -1
