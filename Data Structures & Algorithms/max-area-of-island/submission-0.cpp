class Solution {
public:
    vector<int> x = {1, - 1, 0, 0};
    vector<int> y = {0, 0, - 1, 1};
    bool valid(int n, int m, int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    void dfs(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<bool>>& vis, int &a) {
        vis[i][j] = true;
        a++;
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];
            if (valid(n, m, row, col) && vis[row][col] == false && grid[row][col] == 1) {
                vis[row][col] = true;
                // a++;
                dfs(grid, n, m, row, col, vis, a);
            }
        }
        return ;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == false) {
                    // vis[i][j] = true;
                    int temp = 0;
                    dfs(grid, n, m, i, j, vis, temp);
                    area = max(area, temp);
                }
            }
        }
        return area;

    }
};
