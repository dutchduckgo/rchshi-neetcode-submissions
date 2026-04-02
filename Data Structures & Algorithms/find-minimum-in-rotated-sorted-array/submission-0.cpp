class Solution {
public:
    int findMin(vector<int> &nums) {
        // 7 8 9 0 1 2 3 4 5 6 --> mr sorted, min in lm
        // 0 1 2 3 4 5 6 7 8 9
        // 4 5 6 7 8 9 0 1 2 3 --> lm sorted, min in mr
        // l       l         r
        
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = (r + l) / 2;

            // check mr sorted
            if (nums[mid] < nums[r]) {
                r = mid; // dont discard mid because it could be the min
            } else {
                // check lm sorted
                l = mid + 1; 
            }
        }
        return nums[l];
    }
};