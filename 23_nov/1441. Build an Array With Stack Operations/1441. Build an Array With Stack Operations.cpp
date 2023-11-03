class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int it=0;
        for(int i=1;i<=n;i++){
            ans.push_back("Push");
            if (i==target[it]){
                it++;
            }
            else {
                ans.push_back("Pop");
            }
            if (it==target.size()){
                return ans;
            }
        }
        return {};
    }
};
