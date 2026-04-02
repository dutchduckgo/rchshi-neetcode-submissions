class DSU {
    vector<int> Parent, Size;
    public:
        DSU(int n) {
            Parent.resize(n + 1);
            Size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                Parent[i] = i;
                Size[i] = 1;
            }
        }

        int find(int n) {
            while (n != Parent[n]) {
                // Parent[n] = Parent[Parent[n]]; // path compression
                n = Parent[n];
            }
            return Parent[n];
        }

        bool unite(int n1, int n2) {
            int p1 = find(n1);
            int p2 = find(n2);
            if (p1 == p2) return false;

            if (Size[p1] > Size[p2]) {
                Parent[p2] = Parent[p1];
                Size[p1] += Size[p2];
            } else {
                Parent[p1] = Parent[p2];
                Size[p2] += Size[p1];
            }
            return true;
        }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        DSU dsu(ROWS * COLS);
        int islands = 0;
        int dir [4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

        for (int r = 0; r < ROWS; r++) {
            
            for (int c = 0;  c < COLS; c++) {
                if (grid[r][c] == '1') {
                    islands ++;
                    for (auto& d : dir) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if (nr >= 0 && nc >= 0 && 
                            nr < ROWS && nc < COLS && 
                            grid[nr][nc] == '1') {
                            if (dsu.unite(r * COLS + c, nr * COLS + nc)) {
                                islands --;
                            }
                        }
                    }

                }
            }
        }
        return islands;
    }
};

