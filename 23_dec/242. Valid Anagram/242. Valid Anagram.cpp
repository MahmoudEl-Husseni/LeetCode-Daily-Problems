class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> fs(26), ft(26);
        for(auto c : s){
            fs[c-'a']++;
        }
        for(auto c : t){
            ft[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if (fs[i]!=ft[i])return false;
        }
        return true;
    }
};
