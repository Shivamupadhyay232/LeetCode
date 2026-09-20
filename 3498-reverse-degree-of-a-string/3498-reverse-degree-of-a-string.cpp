class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        unordered_map<char,int>m;
        int i=26;
        for(char ch='a';ch<='z';ch++){
            m[ch]=i;
            i--;
        }
        int sum=0;
        for(int j=0;j<n;j++){
            sum=sum+((j+1)*m[s[j]]);
        }
        return sum;
    }
};