class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int m=0, p=0, g=0;
        int mm=0, pp=0, gg=0;
        for(int i=0;i<garbage.size();i++){
            string s = garbage[i];
            for (auto c : s){
                if (c=='M'){
                    m=i;
                    mm++;
                }
                else if(c=='P') {
                    p=i;
                    pp++;
                }
                else if (c=='G'){
                    g = i;
                    gg++;
                }
            }
        }
        int ans = 0;
        int ps = 0;
        for(int i=1;i<garbage.size();i++){
            ps += travel[i-1];
            if (i==m)ans+=ps;
            if (i==g)ans+=ps;
            if (i==p)ans+=ps;
        }
        ans += mm;
        ans += pp;
        ans += gg;
        return ans;
    }
};
