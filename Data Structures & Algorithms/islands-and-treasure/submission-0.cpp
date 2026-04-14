class Solution {
public:
    vector<int> x = {- 1, 1, 0, 0};
    vector<int> y = {0, 0, - 1, 1};
    bool valid(int n, int m, int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
   
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        // vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    // vis[i][j] = true;
                }
            }
        }
        int dist = 0;
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int row = temp.first + x[k];
                int col = temp.second + y[k];
                if (valid(n, m, row, col) && grid[row][col] == INT_MAX) {
                    q.push({row, col});
                    grid[row][col] = grid[temp.first][temp.second] + 1;
                }
            }
        }
        return ;
    }
};
