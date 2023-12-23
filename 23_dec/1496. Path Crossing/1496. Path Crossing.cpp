class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> st;
        st.insert({0, 0});
        int x=0, y=0;
        for(auto c : path){
            if (c=='N'){
                y++;
            }
            else if (c=='S'){
                y--;
            }
            else if (c=='W'){
                x++;
            }
            else x--;
            if (st.count({x, y})) return true;
            st.insert({x, y});
        }
        return false;
    }
};
