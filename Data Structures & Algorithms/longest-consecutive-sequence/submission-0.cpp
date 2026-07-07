class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs(nums.begin(), nums.end());

        int longest = 0;
        for (int n : nums) {
            if (!hs.contains(n - 1)) { // nums[i] could be start of sequence
                int len = 1;
                int d = 1;
                while (hs.contains(n + d)) {
                    len++;
                    d++;
                }
                longest = max(longest, len);
            } 
        }
        return longest;

    }
};
