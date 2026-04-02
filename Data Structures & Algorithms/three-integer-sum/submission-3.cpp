class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> rslt;
        if (nums[0] > 0) return rslt;

        int i = 0;
        while (i <= nums.size() - 3) {
            int l = i + 1, r = nums.size() - 1;
            int target = -1 * nums[i]; 
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    rslt.push_back(vector<int> {-1 * target, nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l - 1]) l ++;
                }
                else if (nums[l] + nums[r] > target) 
                    r--;
                else 
                    l++;
                
            }
            i++;
            while (nums[i] == nums[i - 1]) i++;
        }
        return rslt;
    }
};
