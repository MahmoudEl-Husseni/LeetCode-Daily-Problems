class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> rows(bank.size()); 
        for (int i=0;i<bank.size();i++){
            for(int j=0;j<bank[i].size();j++){
                if (bank[i][j]=='1'){
                    rows[i]++;
                }
            }
        }
        int last = 0, ans=0;
        for(int i=0;i<bank.size();i++){
            ans += rows[i] * last;
            if (rows[i]!=0)
                last = rows[i];
        }
        return ans;
    }
};
