class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.length()>s.length()) {
            return ans;
        }

        int freqP[26]={0};
        int freqWin[26]={0};
        for (char ch:p) {
            freqP[ch-'a']++;
        }

        int left=0;
        for (int right=0;right<s.length();right++) {
            freqWin[s[right] - 'a']++;
            if (right-left+1> p.length()) {
                freqWin[s[left]-'a']--;
                left++;
            }
            if (right - left + 1 == p.length()) {
                bool same=true;
                for (int i=0;i<26;i++) {
                    if (freqP[i]!=freqWin[i]) {
                        same=false;
                        break;
                    }
                }
                if (same){
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};