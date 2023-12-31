class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> last(26, -1); 
        int mx = -1;
        for(int i=0;i<s.size();i++){
            if (last[s[i]-'a']!=-1){
                mx = max(mx, i-last[s[i]-'a']-1);
            }
            else {
                last[s[i]-'a']=i;
            }
        }
        return mx;
    }
};
