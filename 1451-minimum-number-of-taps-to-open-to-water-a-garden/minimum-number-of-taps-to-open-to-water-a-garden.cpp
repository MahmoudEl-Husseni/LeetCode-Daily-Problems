class Solution {
public:

    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for (int i=0;i<=n;i++){
            int l = max(0, i-ranges[i]), r = min(n, i+ranges[i]);
            for(int j=l+1;j<=r;j++){
                dp[j] = min(dp[j], dp[l]+1);
            }
        }
        // for(int i=0;i<=n;i++) cout << dp[i] << " ";
        if (dp[n]==1e9){
            return -1;
        }
        else 
            return dp[n];
    }
};