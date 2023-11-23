class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(), 1);
        for(int i=0;i<l.size();i++){
            vector<int> tmp = nums;
            sort(tmp.begin()+l[i], tmp.begin()+r[i]+1);            
            for(int j=l[i]+1;j<r[i];j++){
                if ((tmp[j]-tmp[j-1])!=tmp[j+1]-tmp[j]){
                    ans[i]=0;
                }
            }
        }
        return ans;
    }
};
