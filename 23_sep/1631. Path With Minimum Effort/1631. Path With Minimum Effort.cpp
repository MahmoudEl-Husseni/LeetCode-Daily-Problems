class Solution {
public:
    bool valid(int x, int y , int n, int m){
        return (x>=0 && x<n && y>=0 && y<m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m = heights[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> dis(n, vector<int>(m, 1e6+1));
        pq.push({0, {0, 0}});
        dis[0][0] = 0;
        while(!pq.empty()){
            auto [c, p] = pq.top();
            pq.pop();
            c*=-1;
            int x=p.first, y=p.second;
            if (dis[x][y]<c) continue;

            if(x==n-1 && y==m-1) return c;

            for(int i=0;i<4;i++){
                int x_ = x+dx[i], y_ = y+dy[i];
                if (!valid(x_, y_, n, m)) continue;
                int w = abs(heights[x][y] - heights[x_][y_]);
                if (dis[x_][y_] > max(c, w)){
                    dis[x_][y_] = max(c, w);
                    pq.push({-dis[x_][y_], {x_, y_}});
                }
            }
        }
        return 0;
    }
};
