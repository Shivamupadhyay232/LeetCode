class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        string left = "";
        string middle = "";
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            for (int j = 0; j < freq[i] / 2; j++) {
                left.push_back(ch);
            }
            if (freq[i] % 2 == 1) {
                middle.push_back(ch);
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left + middle + right;
    }
};