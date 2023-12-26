class Solution {
public:
    int mem[31][1001];
    int mod = 1e9+7;
    int add(int a, int b){
        return (a%mod + b%mod) % mod;
    }
    int rec(int n, int sm, int k){
        // base cases
        if (n==0 && sm==0){
            return 1;    
        }
        if (sm<=0 || n<=0)
            return 0;
        
        // memoization
        int &ret = mem[n][sm];
        if (~ret) 
            return ret;

        // transition
        ret = 0;
        for (int i=1;i<=k;i++){
            ret = add(ret, rec(n-1, sm-i, k));
        }
        return ret;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(mem, -1, sizeof mem);
        return rec(n, target, k);      
    }
};
