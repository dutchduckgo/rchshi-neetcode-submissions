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
            if (countT.count(c)) {
                window[c]++;
                if (window[c] == countT[c]) 
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
                char lc = s[l];
                if (countT.count(lc)) {
                    window[lc]--;
                    if (window[lc] < countT[lc]) 
                        have--;
                }
                
                
                l++;
            }
        }
        if (rsltLen != INT_MAX) return s.substr(rslt.first, rsltLen);
        return "";
    }
};
