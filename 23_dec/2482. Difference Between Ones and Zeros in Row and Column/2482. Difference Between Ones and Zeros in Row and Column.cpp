class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<int> orows(m), ocols(n), zrows(m), zcols(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ocols[i]+=grid[i][j];
                orows[j]+=grid[i][j];
                zrows[j]+=grid[i][j]==0;
                zcols[i]+=grid[i][j]==0;
            }
        }
        vector<vector<int>> diff(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                diff[i][j] = orows[j]+ocols[i]-zrows[j]-zcols[i];
            }
        }
        return diff;
    }
};
