class Solution {
public:
    int maxScore(string s) {
        int ans = 0, sm=0;
        vector<int> n_zeros(s.size());
        n_zeros[0] = s[0]=='0';
        for (int i=1;i<s.size();i++){ 
            n_zeros[i] = n_zeros[i-1] + (s[i]=='0');
        }
        for(int i=s.size()-1;i>=1;i--){
            sm+=(s[i]-'0');

            ans = max(ans, sm+n_zeros[i-1]);
        }
        return ans;
        
    }
};
