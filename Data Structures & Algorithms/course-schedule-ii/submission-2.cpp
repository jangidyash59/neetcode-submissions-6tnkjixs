class Solution {
public:
    // bool cycle = false;
    // void dfs(vector<vector<int>>& adj, int node, vector<bool>& path, vector<bool>& vis) {
    //     vis[node] = true;
    //     path[node] = true;
    //     for (int i = 0; i < adj[node].size(); i++) {
    //         int neigh = adj[node][i];
    //         if (vis[neigh] == true && path[neigh] == true) {
    //             cycle = true;
    //             return ;
    //         }
    //         else {
    //             dfs(adj, neigh, path, vis);
    //         }
    //     }
    //     path[node] = false;
    //     return ;
    // }






















    bool cycle = false;
    void func(vector<vector<int>>& adj, int node, vector<bool>& path, vector<bool>& vis) {
        vis[node] = true;
        path[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i];
            if (vis[neigh] == true && path[neigh] == true) {
                cycle = true;
                return ;
            }
            else {
                func(adj, neigh, path, vis);
            }
        }
        path[node] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> res;
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int src = prerequisites[i][1];
            int dst = prerequisites[i][0];
            adj[src].push_back(dst);
            indeg[dst]++;
        }
        vector<bool> path(n, false);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                func(adj, i, path, vis);
            }
        }
        
        if (cycle) return res;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)  q.push(i);
        }
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            res.push_back(top);
            for (int i = 0; i < adj[top].size(); i++) {
                int neigh = adj[top][i];
                indeg[neigh]--;
                if (indeg[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        return res;

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int v = numCourses;
        // vector<int> res;
        // vector<vector<int>> adj(v);
        // vector<bool> vis(v, false);
        // vector<bool> path(v, false);
        // vector<int> ind(v, 0);
        // queue<int> q;
        // for (int i = 0; i < prerequisites.size(); i++) {
        //     int src = prerequisites[i][1];
        //     int dst = prerequisites[i][0];
        //     adj[src].push_back(dst);
        //     ind[dst]++;
        // }
        // for (int i = 0; i < v; i++) {
        //     if (vis[i] == false) {
        //         dfs(adj, i, path, vis);
        //     }
        // }
        // if (cycle)  return res;
        // for (int i = 0; i < v; i++) {
        //     if (ind[i] == 0) {
        //         q.push(i);
        //     }
        // }
        // while (!q.empty()) {
        //     int top = q.front();
        //     q.pop();
        //     res.push_back(top);
        //     for (int i = 0; i < adj[top].size(); i++) {
        //         int neigh = adj[top][i];
        //         ind[neigh]--;
        //         if (ind[neigh] == 0) {
        //             q.push(neigh);
        //         }
        //     }
        // }
        // return res;
        
    }
};
