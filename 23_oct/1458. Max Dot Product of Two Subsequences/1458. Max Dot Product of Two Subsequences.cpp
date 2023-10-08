class Solution {
public:
    int mem[501][501][2];
    int rec(int i, int j, int cnt, vector<int>& nums1, vector<int>& nums2){
        if (i==nums1.size() && j==nums2.size()) {
            if (cnt==0) return -1e9-7;
            return 0;
        }

        int &ret = mem[i][j][cnt];
        if(~ret) 
            return ret;
        ret = -1e9-7;

        if (i<nums1.size() && j<nums2.size()) 
            ret = rec(i+1, j+1, 1, nums1, nums2)+nums1[i]*nums2[j];
        if(i<nums1.size()){
            ret = max(ret, rec(i+1, j, cnt, nums1, nums2));
        }
        if (j<nums2.size()){
            ret = max(ret, rec(i, j+1, cnt, nums1, nums2));
        }
        return ret;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(mem, -1, sizeof mem); 
        return rec(0, 0, 0, nums1, nums2);
    }
};
