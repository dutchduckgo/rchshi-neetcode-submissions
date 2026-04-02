class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // add all stones[i] to maxHeap

        // while maxHeap.size() > 1, pop the top two, compute diff,
        // if diff == 0, continue
        // push diff

        priority_queue<int> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int s1 = maxHeap.top();
            maxHeap.pop();
            int s2 = maxHeap.top();
            maxHeap.pop();

            int diff = s1 - s2;
            if (diff == 0) {
                continue;
            }
            // else, s1 has weight of diff, add s1 back into maxHeap
            maxHeap.push(diff);
        }
        if (maxHeap.size() == 0) return 0;
        return maxHeap.top();
        // max heap
        // add: logN
        // pop: logN
    }
};
