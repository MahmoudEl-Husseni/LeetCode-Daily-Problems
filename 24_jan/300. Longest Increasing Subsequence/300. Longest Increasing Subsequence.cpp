class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        dp[n-1]=1;
        int ans=0;
        for(int i=n-1;i>=0;i--) {
            for (int j=i+1;j<n;j++) {
                if (nums[j]>nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
