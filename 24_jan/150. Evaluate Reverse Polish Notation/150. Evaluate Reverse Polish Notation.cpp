class Solution {
public:
    int strtoi(string &s){
        int ans=0;
        bool f = s[0]=='-';
        if (f)
            s=s.substr(1, s.size()-1);
        for (auto c : s){
            ans *=10;
            ans += int(c-'0');
        }
        if (f)
            ans*=-1;
        return ans;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto c : tokens){
            if (c != "+" && c!="-" && c!="/" && c!="*"){
                st.push(strtoi(c));
            }
            else if (c=="+"){
                int f=st.top();st.pop();
                int s = st.top();st.pop();
                st.push(f+s);
            }
            else if (c=="*"){
                int f=st.top();st.pop();
                int s = st.top();st.pop();
                st.push(f*s);
            }
            else if (c=="-"){
                int f=st.top();st.pop();
                int s = st.top();st.pop();
                st.push(s-f);
            }
            else if (c=="/"){
                int f=st.top();st.pop();
                int s = st.top();st.pop();
                st.push(s/f);
            }
        }
        return st.top();
    }
};
