class Solution {
public:
    int minOperations(string s) {
        int s1=0, s2=0, f=0;
        for(auto c : s){
            if (c=='0'+f){
                s2++;
            }
            else {
                s1++;
            }
            f=1-f;
        }
        return min(s1, s2);
    }
};
