class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // calculate dist of each pt (dist^2)
        // minHeap of (dist, point);
        // pop minHeap k times

        // create minHeap of pair (dist, point);
        priority_queue<
            pair<int, vector<int>>, 
            vector<pair<int, vector<int>>>, 
            greater<pair<int, vector<int>>>
        > minHeap;

        for (vector<int>& pt : points) {
            int dist = pt[0] * pt[0] + pt[1] * pt[1];
            pair<int,vector<int>> dist_pt(dist, pt);
            minHeap.push(dist_pt);
        }

        vector<vector<int>> res;
        while (k--) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;

    }
};
