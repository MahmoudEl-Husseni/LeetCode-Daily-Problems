class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> power;
        int n=mat.size(), m=mat[0].size();
        for(int i=0;i<n;i++){
            int l=0, r=m-1, md;
            while(l<r){
                md = l + (r-l+1) / 2;
                if(mat[i][md]) l=md;
                else r=md-1;
            }
            power.push_back({l+mat[i][l], i});
        }
        sort(power.begin(), power.end());
        vector<int> ans;
        while(k--){
            ans.push_back(power[k].second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};