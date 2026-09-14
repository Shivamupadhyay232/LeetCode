class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        stack<int>st;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(!st.empty()){
                    ans=ans+'(';

                }
                st.push(s[i]);
                
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans=ans+')';
                }

                
            }
        }
        return ans;
    }
};