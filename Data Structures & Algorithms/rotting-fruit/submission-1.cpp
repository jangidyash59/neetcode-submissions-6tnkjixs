class Solution {
public:
    vector<int> x = {- 1, 1, 0, 0};
    vector<int> y = {0, 0, - 1, 1};
    bool valid(int n, int m, int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int timer = 0;
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }
        while (!q.empty() && fresh > 0) {
            int s = q.size();
            timer++;
            while (s--) {
                pair<int, int> temp = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int row = temp.first + x[k];
                    int col = temp.second + y[k];
                    if (valid(n, m, row, col) && grid[row][col] == 1) {
                        fresh--;
                        q.push({row, col});
                        grid[row][col] = - 1;
                    }
                }
            }
        }
        return (fresh == 0) ? timer : -1;
    }
};
