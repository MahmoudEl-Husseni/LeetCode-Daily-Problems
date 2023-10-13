class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 1e9);
        dp[n-1] = cost[n-1];
        for(int i=n-2;i>=0;i--){
            if(i+1<n) dp[i] = min(dp[i+1] + cost[i], dp[i]);
            if(i+2<n) dp[i] = min(dp[i+2] + cost[i], dp[i]);
            else dp[i] = min(cost[i], dp[i]);
        }
        
        return min(dp[0], dp[1]);
    }
};
