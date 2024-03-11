class Solution {
public:
    bool dfsCheck(int node, vector<int> adj[], vector<int> &vis,vector<int> &pathVis) {
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
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        for(int i = 0 ; i < V ; i++) {
            if(!vis[i] and dfsCheck(i, adj, vis, pathVis)) {
                return false;
            }
        }
        return true;
    }
};