class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window of (l,r)
        // unordered_set to store chars within the winodw
        // update bag as window shifts
        // r, check if new char exists in bag, if not add to bag, update max len
        // if exists, increment l, remove char from bag, check again (looped)

        unordered_set<char> bag;
        int res = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            char cur = s[r];

            while (bag.find(cur) != bag.end()) {
                bag.erase(s[l]);
                l++;
            }
            bag.insert(s[r]);
            res = max(res, r - l + 1);

        }
        return res;
    }
};
