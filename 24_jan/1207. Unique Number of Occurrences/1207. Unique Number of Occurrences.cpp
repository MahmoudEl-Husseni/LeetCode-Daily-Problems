class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        set<int> st; 
        for(auto [f, s] : freq){
            if (st.count(s))
                return false;
            st.insert(s);
        }
        return true;
    }
};
