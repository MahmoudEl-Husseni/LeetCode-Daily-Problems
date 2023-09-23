class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map< string , int > mp ;
        sort (words.begin() , words.end() , [](const string & a , const string & b)
        {return a.size() < b.size();}) ;
        int ans = 0 ;
        for (auto& s : words)
        {
            string t = s ;
            t.pop_back() ;
            int i = s.size()-1;
            while(i>0)
            {
                mp[s] = max(mp[s] , mp[t]+1);
                t[i-1] = s[i];
                i--;
            }
            mp[s] = max(mp[s] , mp[t]+1);
            ans = max (ans , mp[s]);
        }
        return ans ;
    }
};
