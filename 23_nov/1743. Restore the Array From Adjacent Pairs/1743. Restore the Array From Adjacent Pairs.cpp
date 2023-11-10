class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& A) {
        int edge; 
        unordered_map<int, vector<int>> mp;
        unordered_map<int, bool> vis;
        for(int i=0;i<A.size();i++){
            int u = A[i][0], v = A[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        for(auto [u, mp] : mp){
            if (mp.size()==1){
                edge = u;
                break;
            }
        }
        int u = edge;
        vector<int> ans;
        for(int i=0;i<=A.size();i++){
            vis[u] = 1;
            ans.push_back(u); 
            for (auto v : mp[u]){
                if (!vis[v]){
                    u = v;
                }
            }
        }
        return ans;
    }
};
