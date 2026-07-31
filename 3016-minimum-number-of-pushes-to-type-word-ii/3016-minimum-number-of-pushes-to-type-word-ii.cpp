class Solution {
public:
    int minimumPushes(string word) {
        int freq[26]={0};
        int ans=0;
        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
        sort(freq,freq+26,greater<int>());
        for(int num=0;num<26;num++){
            if(freq[num]==0){
                break;
            }
            else{
                ans=ans+freq[num]*((num/8)+1);
            }
        }
        return ans;
    }
};