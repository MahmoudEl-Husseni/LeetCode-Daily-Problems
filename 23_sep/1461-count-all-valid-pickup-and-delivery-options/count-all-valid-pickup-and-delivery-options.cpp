class Solution {
public:
    const int MOD = 1e9+7;
    long long mem[501];
    long long rec(int i){
        if(i==0){
            return 1;
        }

        long long &ret = mem[i];
        if (~ret) return ret;

        return ret = (rec(i-1) * ((i*(2*i-1)) % MOD))%MOD;
    }

    int countOrders(int n) {
        memset(mem, -1, sizeof mem);
        return rec(n);
    }
};


// PPDD -> 4
// PDPD -> 2

// PPPDDD -> 6*6 = 36
// PPDDPD -> 4*3 = 12
// PDPPDD -> 4*3 = 12
// PPDPDD -> 
// PDPDPD -> 1*3 = 3