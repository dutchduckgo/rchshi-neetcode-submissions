class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // hashmap freq table
        // convert our ft to bucket sort array
        unordered_map<int, int> freq;
        // n -> count
        for (int n : nums) {
            freq[n]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        
        for (auto& [key, value] : freq) {
            bucket[value].push_back(key);
        }   

        vector<int> rslt;
        for (int i = bucket.size() - 1; i > 0; i --) {
            if (!bucket[i].empty()) {
                for (int val : bucket[i]) {
                    rslt.push_back(val);
                    if (rslt.size() == k) return rslt;
                }
            }
        }

        return rslt;

    }
};
