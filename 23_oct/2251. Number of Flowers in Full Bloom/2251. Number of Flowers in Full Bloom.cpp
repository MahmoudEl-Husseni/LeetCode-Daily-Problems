class Solution {
public:
int lst_finish(vector<vector<int>>& flowers, int day){
    int l = -1, r= flowers.size()-1;
    while(l<r){
        int mid = l + (r-l+1)/2;
        if (flowers[mid][1]<day)
            l = mid;
        else
            r = mid-1;
    }
    return l;
}
int fst_start (vector<vector<int>>& flowers, int day){
    int l = 0, r= flowers.size();
    while(l<r){
        int mid = l + (r-l)/2;
        if (flowers[mid][0]>day)
            r = mid;
        else
            l = mid+1;
    }
    return l;
}
vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    sort(flowers.begin(), flowers.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    vector<vector<int>> flowers2 = flowers;
    sort(flowers2.begin(), flowers2.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int n = flowers.size();
    vector<int> ans(people.size());
    for(int i=0;i<people.size();i++){
        int day = people[i];
        int l = lst_finish(flowers2, day);
        int r = fst_start(flowers, day);
        ans[i] = n - l - (n-r) - 1;
    }
    return ans;
}
};
