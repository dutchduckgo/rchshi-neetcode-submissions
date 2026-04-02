class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>, vector<string>> um;

        for (string& s : strs) {
            vector<int> word_hm(26, 0);
            for (char c : s) {
                word_hm[c - 'a']++;
            }
            um[word_hm].push_back(s);
        }
        vector<vector<string>> rslt;

        for (auto& [key, value] : um) {
            rslt.push_back(value);
        }

        return rslt;
    }
};
