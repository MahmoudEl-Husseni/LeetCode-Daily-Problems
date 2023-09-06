class Solution {
public:
    int mem[51];
    int rec(int i, string s, vector<string>& dict){
        int n = s.size();
        if(i==n) return 0;

        int &ret = mem[i];
        if(~ret) return ret;
        ret = 1e9;
        for(int j=i+1;j<=n;j++) {
            string t = s.substr(i, j-i);
            auto it = find(dict.begin(), dict.end(), t);
            ret = min(ret, int(rec(j, s, dict) + (j-i)*(it==dict.end())));
        }
        return ret;
    }
    int minExtraChar(string s, vector<string>& dict) {
        memset(mem, -1, sizeof mem);
        return rec(0, s, dict);
    }
};