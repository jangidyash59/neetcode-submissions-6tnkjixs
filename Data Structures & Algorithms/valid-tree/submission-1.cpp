class Solution {
public:
    bool cycle = false;
    void dfs(vector<vector<int>>& adj, int node, int parent, vector<bool>& vis) {
        vis[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i];
            if (neigh == parent) {
                continue;
            }
            if (vis[neigh] == true) {
                cycle = true;
                return ;
            }
            else {
                dfs(adj, neigh, node, vis);
            }
        }
        return ;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for (int i = 0; i < edges.size(); i++) {
            int src = edges[i][0];
            int dst = edges[i][1];
            adj[src].push_back(dst);
            adj[dst].push_back(src);
        }
        dfs(adj, 0, - 1, vis);
        for (auto it : vis) {
            if (it == false) {
                return false;
            }
        }
        return !cycle;
    }
};
