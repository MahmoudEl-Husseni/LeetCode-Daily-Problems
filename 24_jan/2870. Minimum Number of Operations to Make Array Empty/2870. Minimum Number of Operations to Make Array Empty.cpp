class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto n : nums)
            mp[n]++;
        
        int ans=0;
        for (auto [_, s] : mp){
            if (s==1) return -1;
            else {
                int odd = s/3;
                if (s-odd*3==1){
                    odd--;
                }
                ans += odd+(s-odd*3)/2;
            }
        }
        return ans;

    }
};
