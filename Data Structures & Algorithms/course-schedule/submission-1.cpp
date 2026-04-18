class Solution {
public:
    bool cycle = false;
    void dfs(vector<vector<int>>& adj_l, int node, vector<bool>& path, vector<bool>& vis) {
        vis[node] = true;
        path[node] = true;
        for (int i = 0; i < adj_l[node].size(); i++) {
            int neigh = adj_l[node][i];
            if (vis[neigh] == true && path[neigh] == true) {
                cycle = true;
                return ;
            }
            else {
                dfs(adj_l, neigh, path, vis);
            }
        }
        path[node] = false;
        return ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_l(numCourses);
        int v = numCourses;
        vector<bool> vis(v, false);
        vector<bool> path(v, false);
        for (int i = 0; i < prerequisites.size(); i++) {
            int src = prerequisites[i][1];
            int dst = prerequisites[i][0];
            adj_l[src].push_back(dst);
        }
        for (int i = 0; i < v; i++) {
            if (vis[i] == false) {
                dfs(adj_l, i, path, vis);
            }
        }
        return !cycle;
    }
};
