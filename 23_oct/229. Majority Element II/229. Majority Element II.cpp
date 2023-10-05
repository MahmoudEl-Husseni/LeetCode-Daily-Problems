class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> ans;
        for(auto n : nums) freq[n]++;
        int n = nums.size();
        for (auto [k, v] : freq){
            if(v>n/3) ans.push_back(k);
        }
        return ans;
    }
};
