class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            mp[groupSizes[i]].push_back(i);
        }
        for(auto [f, s] : mp){
            int t = s.size()-1, i=ans.size();
            while(t>=0){
                ans.push_back({});
                for(int j=0;j<f;j++,t--){
                    ans[i].push_back(s[t]);
                }
                i++;
            }
        }
        return ans;
    }
};