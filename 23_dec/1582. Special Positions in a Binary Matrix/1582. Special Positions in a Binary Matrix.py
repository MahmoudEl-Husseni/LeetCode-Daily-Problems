class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        rows = [0] * len(mat)
        cols = [0] * len(mat[0])
        for i in range(len(mat)) : 
            for j in range(len(mat[i])) :
                cols[j] += mat[i][j]
                rows[i] += mat[i][j]
        
        ans = 0
        for i in range(len(mat)) : 
            for j in range(len(mat[i])) :
                ans += rows[i]==1 and cols[j]==1 and mat[i][j]
        
        
        return ans
