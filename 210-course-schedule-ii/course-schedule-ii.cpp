class Solution {
public:
    vector<int> ans;
    void dfs_topo(int node, vector<int> adj[], vector<int> &visited) {
        visited[node] = 1;
        for(auto it : adj[node]) {
            if(!visited[it]) {
                dfs_topo(it, adj, visited);
            }
        }
        ans.push_back(node);
    }
    bool dfsCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfsCheck(it, adj, vis, pathVis)) return true;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node] = 0;
        return false;
    }
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> visited(V, 0);
        //if cycle is detected then there is not topo sort
        bool flag = true;
        for(int i = 0 ; i < V ; i++) {
            if(!vis[i] and dfsCheck(i, adj, vis, pathVis)) {
                flag = false;
                break;
            }
        }
        
        if(flag == false) return ans;
        else {
            for(int i = 0 ; i < V ; i++) {
                if(!visited[i]) {
                    dfs_topo(i, adj, visited);
                }
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
};