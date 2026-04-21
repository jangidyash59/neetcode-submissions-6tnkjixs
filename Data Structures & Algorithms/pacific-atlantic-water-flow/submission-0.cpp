class Solution {
public:
    bool valid(int n, int m, int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        int n = heights.size();
        int m = heights[0].size();
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int nr = r + x[k];
            int nc = c + y[k];
            if (valid(n, m, nr, nc) && vis[nr][nc] == false && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, nr, nc, vis);
            }
        }
        return ;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        // vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));  
        for (int i = 0; i < n; i++) {
            dfs(heights, i, 0, pac);
        }
        for (int j = 0; j < m; j++) {
            dfs(heights, 0, j, pac);
        }
        for (int i = 0; i < n; i++) {
            dfs(heights, i, m - 1, atl);
        }
        for (int j = 0; j < m; j++) {
            dfs(heights, n - 1, j, atl);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;

    }
};
