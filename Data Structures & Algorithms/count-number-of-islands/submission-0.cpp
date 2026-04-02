class Solution {
public:
    int ROWS;
    int COLS;
    int res;

    void dfs (int r, int c, vector<vector<char>>& grid) {
        if (r < 0 || r == ROWS || c < 0 || c == COLS || grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';
        dfs (r + 1, c, grid);
        dfs (r - 1, c, grid);
        dfs (r, c + 1, grid);
        dfs (r, c - 1, grid);

    }

    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        res = 0;

        for (int r = 0; r < ROWS; r ++) {
            for (int c = 0; c < COLS; c ++) {
                if (grid[r][c] == '1') {
                    dfs(r, c, grid);
                    res ++;
                }
                
            }
        }
        return res;
    }
};
