class Solution {
public:
    int mem[301][1001][11];
    int rec(int i, int mx, int d, int n, vector<int>& diff){
        if (i==n){
            if (d!=0) 
                return 1e9;
            else return mx;
        }
        if (d<0) return 1e9;

        int &ret = mem[i][mx][d];
        if (~ret) 
            return ret;

        // take i in the same day
        int cur = rec(i+1, max(mx, diff[i]), d, n, diff);
        // take i in the next day
        int nxt = mx+rec(i+1, diff[i], d-1, n, diff);
        
        return ret=min(cur, nxt);

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(mem, -1, sizeof mem);
        int ans = rec(0, 0, d, jobDifficulty.size(), jobDifficulty);
        if (ans==1e9) 
            return -1;
        else return ans;
    }
};
