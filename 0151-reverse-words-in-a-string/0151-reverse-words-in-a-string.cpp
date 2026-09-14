class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        vector<string>v;

        int i=0;
        string ans="";
        while(i<n){
            
            if(s[i]!=' '){
                ans+=s[i];
                i++;
            }
            else{
                if(ans.size()!=0){

                    v.push_back(ans);
                    ans="";
                }
                i++;
            }

        }
        if(ans!=""){
            v.push_back(ans);
        }
        string fin="";
        for(int i=v.size()-1;i>=1;i--){
            fin+=v[i];
            fin+=" ";
        }
        fin+=v[0];
        return fin;


    }
};