class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans(nums.size()/3, vector<int>(3));
        ans[0][0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if (i%3==0){
                ans[i/3][i%3]=nums[i];
            }
            else if ((i%3==2 && (nums[i]-nums[i-1])<=k && (nums[i]-nums[i-2])<=k) || 
                      i%3==1 && (nums[i]-nums[i-1]) <=k ){
                ans[i/3][i%3]=nums[i];
            }
            else {
                cout << nums[i] << " " << nums[i-1] << endl;
                return vector<vector<int>>();
            }
        }   
        return ans;
    }
};
