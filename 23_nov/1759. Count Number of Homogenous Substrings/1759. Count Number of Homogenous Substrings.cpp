class Solution {
public:
    long long mul(long long a, long long b, int mod){
        return (a%mod * b%mod) % mod;
    }
    int add(int a, int b, int mod){
        return (a%mod + b%mod) % mod;
    }

    int countHomogenous(string s) {
        char t = s[0];
        long long l = 1, mod = 1e9+7;
        long long ans = 0;
        for(int i=1;i<s.size();i++){
            if (s[i-1]==s[i]){
                l++;
                l%=mod;
            }
            else {
                t = s[i];
                ans = add(ans, mul(l, l+1, mod) / 2, mod);
                l=1;
            }
        }
        ans = add(ans, mul(l, l+1, mod) / 2, mod);
        return ans;
    }
};
