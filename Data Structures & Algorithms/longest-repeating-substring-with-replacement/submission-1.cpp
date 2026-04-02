class Solution {
public:

    int findMax (vector<int>& freq) {
        int res = 0;
        for (int i : freq) {
            res = max(res, i);
        }
        return res;
    }

    int characterReplacement(string s, int k) {
        vector<int> freq(26);

        int i = 0, j = 0;
        int res = 0;

        // AAA BA BB
        // maxFreq + k <= len
        while (i < s.size() && j < s.size()) {
            // update freq
            // find maxFreq
            // check maxFreq + k <= len
            // if yes increment j, if no, increment i
            int len = j - i + 1;
            freq[s[j] - 'A']++;
            int maxFreq = findMax(freq);
            if (maxFreq + k >= len) {
                res = max(res, len);
                j++;
            } else {
                freq[s[i] - 'A']--;
                freq[s[j] - 'A']--;
                i++;
            }
        }
        return res;
    }
};
