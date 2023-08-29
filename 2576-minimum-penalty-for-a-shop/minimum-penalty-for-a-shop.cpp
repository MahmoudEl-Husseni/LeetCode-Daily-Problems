class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pref(n+1);
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1] + (customers[i-1]=='Y');
        }
        int mn = n, tot=pref[n], ans;
        for(int i=0;i<=n;i++){
            int penality = i - pref[i];
            penality += tot - pref[i];
            if (penality < mn){
                mn = penality;
                ans = i;
            }
        }
        return ans;
    }
};