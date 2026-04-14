class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tgt) {
        int i = 0; 
        int j = nums.size() - 1;

        while (i < j) {
            int cur = nums[i] + nums[j];
            if (cur == tgt) return {i + 1, j + 1};
            if (cur > tgt)
                j--;
            else 
                i++;
        }
        return {};
    }
};
