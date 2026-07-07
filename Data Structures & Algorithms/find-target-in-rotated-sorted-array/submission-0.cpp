class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int pivot = l;
        l = 0;
        r = nums.size() - 1;

        if (nums[pivot] <= target && target <= nums[r]) {
            l = pivot;
        } else {
            r = pivot - 1;
        }

        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            } 
            if (target > nums[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return -1;
    }
};
        
