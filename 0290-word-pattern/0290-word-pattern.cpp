class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        stringstream ss(s);
        string word;
        int i=0;
        while(ss >> word){
            if(i==pattern.length())return false;
            if(mp1.find(pattern[i])!=mp1.end()){
                if(mp1[pattern[i]]!=word){
                    return false;
                }
            }
            else{
                mp1[pattern[i]]=word;
            }
            if(mp2.find(word)!=mp2.end()){
                if(mp2[word]!=pattern[i]){
                    return false;
                }
            }
            else{
                mp2[word]=pattern[i];
            }
            i++;
        }
        if(i!=pattern.length()){
            return false;
        }
        return true;
    }
};