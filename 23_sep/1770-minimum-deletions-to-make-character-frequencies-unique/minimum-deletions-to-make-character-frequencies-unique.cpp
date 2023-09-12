class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        vector<int> freq(26);
        set<int> st;
        for(auto c : s){
            freq[c-'a']++;
        }
        sort(freq.begin(), freq.end());
        for(int i=24;i>=0;i--){
            if(freq[i]==0)
                continue;
            if(freq[i]>=freq[i+1]){
                int d = freq[i]-freq[i+1]+(freq[i+1]!=0);
                ans+=d;
                freq[i]-=d;
            }
        }
        return ans;
    }
};

// 1 1 1 4
// 0 0 1 4