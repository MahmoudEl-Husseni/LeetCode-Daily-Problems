class Solution {
public:
    bool vowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' ||c=='O' || c=='U'; 
    }
    string sortVowels(string s) {
        unordered_map<char, int> mp;
        for(auto c : s){
            if (vowel(c))
                mp[c]++;
        }
        vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        int it=0;
        for(auto &c : s){
            if (vowel(c)){
                while (!mp[vowels[it]]){
                    it++;
                }
                c = vowels[it];
                mp[vowels[it]]--;
            }
        } 
        return s;
    }
};
