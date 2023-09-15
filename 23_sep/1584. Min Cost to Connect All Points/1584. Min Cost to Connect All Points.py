class DSU: 
    def __init__(self, n): 
        self.par = [*range(n)]
        self.sz = [1] * n
    
    def find (self, u): 
        if self.par[u]!=u: 
            self.par[u] = self.find(self.par[u])
        return self.par[u]
    
    def join(self, u, v): 
        u , v = self.find(u), self.find(v)

        if(u==v): 
            return False
        if self.sz[v]>self.sz[u]: 
            v, u = u, v
        
        self.par[v] = u
        self.sz[u] += self.sz[v]
        return True
        
class Solution:
    
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        edges = []

        for i in range(n): 
            for j in range(i+1, n):
                d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])
                edges.append([d, i, j])

        edges = sorted(edges)

        n_edges, ans = 0, 0
        dsu = DSU(n)
        for e in edges:
            if dsu.join(e[1], e[2]): 
                ans += e[0]
                n_edges+=1

            if n_edges==(n-1): 
                return ans

        return 0

