class Solution {
public:
    int maxArea(vector<int>& heights) {
        int rslt = 0;
        int i = 0;
        int j = heights.size() - 1;
        while (i < j) {
            int lesser = min(heights[i], heights[j]);
            rslt = max(rslt, lesser * (j - i));
            if (lesser == heights[i]) {
                i ++;
            } else {
                j --;
            }
        }
        return rslt;
    }
};
