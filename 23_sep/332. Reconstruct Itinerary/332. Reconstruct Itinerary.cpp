class Solution {
public:
    map<string, vector<pair<string, bool>>> grid;
    vector<string> ans;
    void DFS(string u) {
        for (auto &[v, f] : grid[u]){
            if (f==0){
                f=1;
                DFS(v);
            }
        }
        ans.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i=0;i<tickets.size();i++){
            string u = tickets[i][0], v = tickets[i][1];
            grid[u].push_back({v, 0}); 
        }
        for(auto &[f, s] : grid){
            sort(s.begin(), s.end());
        }
        DFS("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
