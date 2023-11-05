class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int, int> matchesWon;
        int n = arr.size();
        int cmx = arr[0];
        for (int i=1; i<n; i++) {
            cmx = max(cmx, arr[i]);
            matchesWon[cmx]++;
            if (matchesWon[cmx] >= k) {
                return cmx;
            }
        }
        return cmx;
    }
};
