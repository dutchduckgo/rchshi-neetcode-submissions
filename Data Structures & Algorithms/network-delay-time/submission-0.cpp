class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       unordered_map<int, vector<pair<int, int>>> adj;

        for (vector<int>& t : times) {
            adj[t[0]].emplace_back(t[1], t[2]);
        }

        vector<int> dist(n + 1, INT_MAX);

        dfs (k, 0, dist, adj);

        int res = *max_element(dist.begin() + 1, dist.end());
        return res == INT_MAX ? -1 : res;

    }

    void dfs (int src, int time, vector<int>& dist, unordered_map<int, vector<pair<int, int>>>& adj) {
        
        if (time > dist[src]) return;
        dist[src] = time;

        for (pair<int,int>& pairs : adj[src]) {
            dfs(pairs.first, time + pairs.second, dist, adj);
        }
    }
};
