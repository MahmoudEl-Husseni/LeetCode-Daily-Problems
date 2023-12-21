class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> st; 
        for (auto pt : points){ 
            st.insert(pt[0]);
        }
        int last = *st.begin();
        int ans=-1;
        for(auto x : st){
            ans = max(ans, x-last);
            last=x;
        }
        return ans;
    }
};
