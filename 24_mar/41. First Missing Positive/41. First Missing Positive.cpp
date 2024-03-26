class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (auto &n : nums){
            if (n<=0 || n>nums.size())
                n=nums.size()+1;
        }
        
        for (int i=0;i<nums.size();i++){
            int n = abs(nums[i]);
            if (n>nums.size())
                continue;
            
            if (nums[n - 1] > 0)
                nums[n-1] = -nums[n-1] ;
        }
        for (int i=1;i<=nums.size();i++){
            if (nums[i-1]>0)
                return i;
        }
        return nums.size()+1;
    }
};
