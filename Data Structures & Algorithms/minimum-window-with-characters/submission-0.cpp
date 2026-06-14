class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") return "";

        unordered_map<char, int> countT, window;
        for (char c : t) 
            countT[c]++;
        
        int have = 0, need = countT.size();
        pair<int, int> rslt;
        int rsltLen = INT_MAX;

        int len = s.size();
        int l = 0;
        for (int r = 0; r < len; r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) != 0 && window[c] == countT[c]) {
                have++;
            }
            while (have == need) {
                // update result
                if (r - l + 1 < rsltLen) {
                    rslt.first = l;
                    rslt.second = r;
                    rsltLen = r - l + 1;
                }
                // pop from left
                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        int fL = rslt.first, fR = rslt.second;
        if (rsltLen != INT_MAX) return s.substr(fL, rsltLen);
        return "";
    }
};
