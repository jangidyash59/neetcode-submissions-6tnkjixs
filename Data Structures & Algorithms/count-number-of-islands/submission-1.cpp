class Solution {
public:
    vector<int> x = {- 1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    bool valid(int r, int c, int n, int m) {
        return !(r < 0 || r >= n || c < 0 || c >= m);
    }
    void dfs(vector<vector<char>>& grid, int n, int m, int i, int j, vector<vector<bool>>& vis) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];
            if (valid(row, col, n, m) && grid[row][col] == '1' && vis[row][col] == false) {
                dfs(grid, n, m, row, col, vis);
            }
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == false) {
                    dfs(grid, n, m, i, j, vis);
                    // vis[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};
