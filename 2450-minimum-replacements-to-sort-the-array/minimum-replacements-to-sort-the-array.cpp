class Solution {
public:
#define ceil(a, b) ((a+b-1) / b)
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0, n = nums.size(); 
        int last = nums[n-1], d;   
        for(int i=n-2;i>=0;i--){
            if (nums[i]>last) {
                d = ceil(nums[i], last);
                last = nums[i] / d;
                // i++;
                ans+=d-1;
            }
            else {
                last = nums[i];
            }
        }
        return ans;
    }
};

// 1 2 3 5 4
// 1 2 3 2 3 4

// 1 2 3 2 3 4
// 1 2 1 2 2 3 4

// 3 9 3
// 3 6 3 3
