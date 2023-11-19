class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums[0], cnt=1, ans=0, m=0;
        for(int i=1;i<nums.size();i++){
            if (nums[i]>l){
                ans += cnt*m;
                cnt = 1;
                m++;
            }
            else {
                cnt++;
            }
            l=nums[i];
        }
        ans += cnt*m;
        return ans;
    }
};
