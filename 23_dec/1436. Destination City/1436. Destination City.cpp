class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> st1, st2;
        for(auto &path : paths){
            st1.insert(path[0]);
            st2.insert(path[1]);
        }
        for(auto i : st2){
            if (st1.count(i)==0){
                return i;
            }
        }
        return "";
    }
};
