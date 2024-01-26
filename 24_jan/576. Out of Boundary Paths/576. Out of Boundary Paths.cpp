class Solution {
public:
    int mem[50][50][51];
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int MOD = 1e9+7;
    int add(int a, int b){
        return (a%MOD + b%MOD) % MOD;
    }
    int rec(int i, int j, int s){
        if (i < 0 || i == m || j < 0 || j == n) 
            return 1;
        if (s==0)
            return 0;
        int &ret = mem[i][j][s];
        if (~ret)
            return ret;
        
        ret=0;
        for (int k=0;k<4;k++){
            int nx=i+dx[k], ny=j+dy[k];
            ret = add(ret, rec(nx, ny, s-1));
        }
        return ret;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(mem, -1, sizeof mem);
        this->m=m;
        this->n=n;
        return rec(startRow, startColumn, maxMove);
    }
};
