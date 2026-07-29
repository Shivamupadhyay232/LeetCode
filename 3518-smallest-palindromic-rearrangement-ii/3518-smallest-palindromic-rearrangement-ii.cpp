class Solution {
public:
    const int MAX = 1000001;

    string smallestPalindrome(string s, int k) {
        vector<int> count(26, 0);

        for (char c : s)
            count[c - 'a']++;

        if (!isPalindromePossible(count))
            return "";

        vector<int> halfCount(26, 0);
        char midLetter = '\0';

        for (int i = 0; i < 26; i++) {
            halfCount[i] = count[i] / 2;
            if (count[i] % 2 == 1)
                midLetter = char('a' + i);
        }

        int totalPerm = countArrangements(halfCount);

        if (k > totalPerm)
            return "";

        string leftHalf = generateLeftHalf(halfCount, k);

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        if (midLetter)
            return leftHalf + string(1, midLetter) + rightHalf;

        return leftHalf + rightHalf;
    }

private:
    bool isPalindromePossible(vector<int>& count) {
        int odd = 0;
        for (int x : count)
            if (x % 2)
                odd++;
        return odd <= 1;
    }

    string generateLeftHalf(vector<int>& halfCount, int k) {
        int halfLen = accumulate(halfCount.begin(), halfCount.end(), 0);
        string left;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (halfCount[i] == 0)
                    continue;

                halfCount[i]--;

                int arrangements = countArrangements(halfCount);

                if (arrangements >= k) {
                    left.push_back(char('a' + i));
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }

        return left;
    }

    int countArrangements(vector<int>& count) {
        int total = accumulate(count.begin(), count.end(), 0);
        long long res = 1;

        for (int freq : count) {
            res *= nCk(total, freq);

            if (res >= MAX)
                return MAX;

            total -= freq;
        }

        return (int)res;
    }

    int nCk(int n, int k) {
        if (k > n)
            return 0;

        k = min(k, n - k);

        long long res = 1;

        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;

            if (res >= MAX)
                return MAX;
        }

        return (int)res;
    }
};