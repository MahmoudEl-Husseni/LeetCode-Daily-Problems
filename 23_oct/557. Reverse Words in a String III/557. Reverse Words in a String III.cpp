class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans="";
        int start = 0;
        for(int i=0;i<n;i++){
            if(s[i]==' ') {
                for(int j=i-1;j>=start;j--){
                    ans+= s[j];
                }
                ans+=' ';
                start = i+1;
            }
        }
        for(int j=n-1;j>=start;j--){
            ans+=s[j];
        }
        return ans;
    }
};
