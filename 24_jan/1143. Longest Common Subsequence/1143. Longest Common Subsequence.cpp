class Solution {
public:
    int mem[1001][1001]; 
    int rec(int i, int j, string& text1, string& text2){
        if (i==text1.size() || j==text2.size())
            return 0;
        int &ret = mem[i][j];
        if (~ret)
            return ret;

        ret=0;
        ret = max(ret, rec(i+1, j+1, text1, text2));
        ret = max(ret, rec(i, j+1, text1, text2));
        ret = max(ret, rec(i+1, j, text1, text2));
        if (text1[i]==text2[j])
            ret = max(ret, rec(i+1, j+1, text1, text2)+1);
        return ret;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(mem, -1, sizeof mem);
        return rec(0, 0, text1, text2);
    }
};
