class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - x;

        if (target < 0)
            return -1;

        if (target == 0)
            return nums.size();

        int n = nums.size();
        int ans = INT_MAX;
        int sm = 0;
        int l = 0, r = 0;

        while (r < n) {
            sm += nums[r];
            r++;

            while (sm > target && l < n) {
                sm -= nums[l];
                l++;
            }

            if (sm == target)
                ans = min(ans, n - (r - l));
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
