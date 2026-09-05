class Solution {
public:
    string addBinary(string a, string b) {
        int l=a.length()-1;
        int m=b.length()-1;
        int carry=0;
        string ans="";
        while(l>=0 ||m>=0 || carry){
            int sum=carry;
            if(l>=0){
                sum+=a[l--]-'0';
            }
            if(m>=0){
                sum+=b[m--]-'0';
            }
            ans+=(sum%2)+'0';
            carry=sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};