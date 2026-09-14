class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        int balance=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(balance!=0){
                    ans=ans+'(';
                }
                balance++;
            }
                
                
                
            
            else{
                balance--;
                if(balance!=0){
                    ans=ans+')';
                }

                
            }
        }
        return ans;
    }
};