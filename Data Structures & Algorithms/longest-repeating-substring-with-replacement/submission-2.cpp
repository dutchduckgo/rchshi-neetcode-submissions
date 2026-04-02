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
        vector<int> freq(26, 0);

        int i = 0;
        int res = 0;
        int maxFreq = 0;

        for (int j = 0; j < s.size(); j ++) {
            int idx = s[j] - 'A';
            freq[idx]++;
            maxFreq = max(maxFreq, freq[idx]);

            while (maxFreq + k < j - i + 1) {
                freq[s[i] - 'A']--;
                i++;
            }
            res = max(res, j - i + 1);


        }
        return res;

        // while (i < s.size() && j < s.size()) {
        //     int len = j - i + 1;
        //     freq[s[j] - 'A']++;
        //     int maxFreq = findMax(freq);
        //     if (maxFreq + k >= len) {
        //         res = max(res, len);
        //         j++;
        //     } else {
        //         freq[s[i] - 'A']--;
        //         freq[s[j] - 'A']--;
        //         i++;
        //     }
        // }
        // return res;
    }
};
