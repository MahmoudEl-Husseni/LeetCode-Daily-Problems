class Solution {
public:    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        queue<tuple<int, int, int>> q;
        set<pair<int, int>> vis;
        
        for(int i = 0; i < n; i++)
        {            
            tuple<int, int, int> node(i, (1 << i), 1);
            q.push(node); 
            vis.insert({i, (1 << i)});
        }
        
        while(q.empty() == false)
        {
            auto [u, mask, c] = q.front();
            q.pop();
            
            if(mask == (1 << n) - 1) 
            {
                return c - 1;
            }
            
            for(auto &v: graph[u])
            {
                if(vis.find({v, mask | (1<<v)}) == vis.end())
                {
                    vis.insert({v, mask | (1<<v)});
                    
                    q.push({v, mask|(1<<v), c + 1});
                }
            }
        }
        return -12;
    }
};
