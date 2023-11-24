class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0;
        sort(piles.rbegin(), piles.rend()); 
        for(int i=1;i<piles.size()*2/3;i+=2){
            ans += piles[i];
        }
        return ans;
    }
};
