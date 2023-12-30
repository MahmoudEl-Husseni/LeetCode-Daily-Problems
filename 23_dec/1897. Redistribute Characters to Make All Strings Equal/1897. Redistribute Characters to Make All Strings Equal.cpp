class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26); 
        for(auto &w : words){
            for (auto &c : w){
                freq[c-'a']++;
            }
        }   
        for(int i=0;i<26;i++){
            if (freq[i]%words.size()!=0) return false;
        }
        return true;
    }
};
