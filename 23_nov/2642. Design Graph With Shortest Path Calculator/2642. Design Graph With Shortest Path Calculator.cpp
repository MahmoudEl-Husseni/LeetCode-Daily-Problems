class Graph {
public:
    vector<vector<int>> a;
    Graph(int n, vector<vector<int>>& edges) {
        a = vector<vector<int>>(n, vector<int>(n, 1e9));
        for(auto e : edges){
            a[e[0]][e[1]] = e[2];
        }

        for(int i=0;i<n;i++){
            a[i][i] = 0;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0], v=edge[1], w=edge[2];
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a.size();j++){
                a[i][j] = min(a[i][j], w+a[i][u]+a[v][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return a[node1][node2]==1e9 ? -1 : a[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
