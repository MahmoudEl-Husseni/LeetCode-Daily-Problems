class Solution {
public:
    int uniquePaths(int m, int n) {
        // (n+m-2) C (m-1)
        long long ans = 1;
        for(int i=1;i<=m-1;i++){
            ans *= 1ll * (n - 1 + i);
            ans /= i;
        }
        return (int)ans;
    }
};