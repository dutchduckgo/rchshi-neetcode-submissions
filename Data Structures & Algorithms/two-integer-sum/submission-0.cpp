class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;
        // n -> index

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (hm.find(diff) != hm.end()) {
                vector<int> rslt = {hm[diff], i};
                return rslt;
            }
            hm[nums[i]] = i;
        }


    }

};
