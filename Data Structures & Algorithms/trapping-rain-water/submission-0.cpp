class Solution {
public:
    int trap(vector<int>& height) {
        // if (height == NULL) return 0;

        int l = 0, r = height.size() - 1;
        int maxL = height[l], maxR = height[r];

        int res = 0;

        while (l < r) {
            if (maxL < maxR) {
                l++;
                maxL = max(maxL, height[l]);
                res += abs(maxL - height[l]);
            } else {
                r--;
                maxR = max(maxR, height[r]);
                res += abs(maxR - height[r]);
            }
        }
        return res;

    }
};
