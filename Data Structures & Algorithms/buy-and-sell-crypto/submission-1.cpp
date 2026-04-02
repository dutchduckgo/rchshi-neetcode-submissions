class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxProf = 0;
        // [10,3,3,6,7,1]
        while (r < prices.size()) {
            int diff = prices[r] - prices[l];
            if (diff > 0) {
                maxProf = max(maxProf, diff);
            } else {
                l = r;
            }
            r++;
        }
        return maxProf;
    }
};
