class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string a = to_string(low), b = to_string(high), seq="123456789";
        int n = b.size(), m = a.size();
        
        vector<int> ans;
        for(int i=0;i<=9;i++)
        {
            for(int j=m;j<=n;j++)
            {
                if (i+j > seq.size()) {
                    break ;
                }
                string tmp = seq.substr(i, j) ;
                int tt = stoi(tmp);
                if (tt >= low && tt <= high) {
                    ans.push_back(tt);
                }
                else if (tmp > b) {
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
