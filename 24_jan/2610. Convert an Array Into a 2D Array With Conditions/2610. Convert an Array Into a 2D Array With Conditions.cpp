class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;
        int mx = 0;
        for(auto num : nums){
            mp[num]++;
            mx = max(mx, mp[num]);
        }
        vector<vector<int>> ans(mx);
        for(auto [f, s] : mp){
            for(int i=0;i<s;i++){
                ans[i].push_back(f);
            }
        }
        return ans;
    }
};
