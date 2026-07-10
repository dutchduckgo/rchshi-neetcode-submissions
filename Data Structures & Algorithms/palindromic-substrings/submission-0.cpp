class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        // find pali of odd len
        for (int i = 0; i < s.size(); i++) {
            res++;
            int len = 1;
            // s[i - 1] s[i + 1]
            // s[i - 2] s[i + 2]
            while (0 <= i - len && i + len <= s.size() - 1) {
                if (s[i - len] == s[i + len]) {
                    res++;
                    len++;
                } else {
                    break;
                }
            }
        }

        // find pali of even len
        for (int i = 0; i < s.size() - 1; i++) {
            int l = i;
            int r = i + 1;

            int len = 0;
            while (0 <= l && r <= s.size() - 1 && s[l] == s[r]) {
                    res++;
                    l--;
                    r++;
            }
        }
        return res;
    }
};
