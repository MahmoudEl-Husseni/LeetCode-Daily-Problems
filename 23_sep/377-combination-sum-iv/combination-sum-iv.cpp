class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       vector<unsigned int> dp(1001+1);
       for(auto num : nums) dp[num]=1;
       for(int i=0;i<=target;i++) {
           for (auto & num : nums){
               if ((i+num) <=target){
                   dp[i+num] += dp[i];
               }
           }
       }
       return dp[target];
    }
};