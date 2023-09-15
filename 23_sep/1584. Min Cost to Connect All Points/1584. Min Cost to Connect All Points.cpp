class Solution {
public:
    int par[1005], sz[1005];
    int find(int u){
        return par[u] = (par[u] == u ? u : find(par[u]));
    }

    bool join(int u, int v){
        u = find(u), v=find(v);
        if(u==v) return false;

        if (sz[u]<sz[v]) swap(u, v);

        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        iota(par, par+n, 0);
        fill(sz, sz+n, 1);
        int ed=0, ans=0;
        for (auto e : edges){
            int dist = e.first, u=e.second.first, v=e.second.second;
            if (join(u, v)){
                ans+=dist;
                ed++;
            }
            if(ed==(n-1)) return ans;
        }
        return 0;
    }
};
