class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       auto it1 = lower_bound(nums.begin(), nums.end(), target);
       auto it2 = upper_bound(nums.begin(), nums.end(), target);
        if (nums.size()<1 || it1==nums.end() || *it1!=target) 
            return {-1, -1};
        
        vector<int> ans(2);
        ans[0] = it1-nums.begin();
        ans[1] = it2-nums.begin()-1;
        return ans; 
    }
};
