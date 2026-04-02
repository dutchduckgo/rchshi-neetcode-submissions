class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_multiset<int> bag;
        
        for (int i : nums) {
            if (bag.find(i) != bag.end()) return true;
            bag.insert(i);
        }
        return false;
    }
};