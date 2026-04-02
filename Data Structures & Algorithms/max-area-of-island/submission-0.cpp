class Solution {

public:
    unordered_set<int> visit;
    int ROWS;
    int COLS;
    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r == ROWS || c < 0 || c == COLS ||
            grid[r][c] == 0 || visit.find(r * COLS + c) != visit.end()) {
                return 0;
        }
        int key = r * COLS + c;
        visit.insert(key);

        return (1 + dfs(r + 1, c, grid) + dfs(r - 1, c, grid) + 
                    dfs(r, c + 1, grid) + dfs(r, c - 1, grid));
        }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        int res = 0;
        for (int r = 0; r < ROWS; r ++) {
            for (int c = 0; c < COLS; c ++) {
                res = max(res, dfs(r, c, grid));
            }
        }
        return res;
    }
};
