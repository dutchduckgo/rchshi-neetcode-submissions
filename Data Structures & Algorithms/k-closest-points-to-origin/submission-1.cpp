class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // calculate dist of each pt (dist^2)
        // minHeap of (dist, point);
        // pop minHeap k times

        // create minHeap of pair (dist, point);
        priority_queue<
            pair<int, vector<int>>, 
            vector<pair<int, vector<int>>>
        > maxHeap;

        for (vector<int>& pt : points) {
            int dist = pt[0] * pt[0] + pt[1] * pt[1];
            pair<int,vector<int>> dist_pt(dist, pt);
            maxHeap.push(dist_pt);
            if (maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;

    }
};
