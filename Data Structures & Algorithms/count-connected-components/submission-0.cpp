class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int n1) {
        int res = n1;
        while (res != parent[res]) {
            parent[res] = parent[parent[res]]; // path compression
            res = parent[res];
        }
        return res;
    }

    int unite(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) return 0;

        if (rank[p2] > rank[p1]) {
            parent[p1] = p2; // add smaller group to larger group
            rank[p2] += rank[p1];
        } else { // rank p1 > p2
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        return 1;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        int res = n;

        for (vector<int>& e : edges) {
            res -= unite(e[0], e[1]); // - either 0 or 1
        }
        return res;

    }
};
