class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            int l=i, r=n-1;
            while(l<r){
                int md = l + (r-l+1) / 2;
                if (arr[md]<=arr[i])
                    l=md;
                else r=md-1;
            }
            if (r-i+1>0.25*n) return arr[i];
            i = l;
        }
        return arr[n-1];
    }
};
