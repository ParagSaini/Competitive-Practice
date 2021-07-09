vector<int> tin, low;
vector<bool> visited;
const int INF = 1e9 + 7;
// given a undirected graph, finding all the bridges
void dfs(int par, int node, vector<int> adj[], int c, int d, int& t, bool& ans) {
    
    visited[node] = true;
    tin[node] = t;
    low[node] = t;
    t++;
    for(auto child : adj[node]) {
        if(child == par) continue;
        if(visited[child] == false) {
            dfs(node, child, adj, c, d, t, ans);
            low[node] = min(low[node], low[child]);
            if(low[child] > tin[node]) {
                // there is bridge between node and child. 
                if((node == c && child == d) || (node == d && child == c)) {
                    ans = true;
                }
            }
        }
        else {
            low[node] = min(low[node], tin[child]);
        }
    }
}
int isBridge(int V, vector<int> adj[], int c, int d)   // vertices from 0 to V-1.
{
    bool ans = false;
    tin.resize(V, INF);
    low.resize(V, INF);
    visited.resize(V, false);
    for(int i=0; i<V; i++) {
        if(visited[i] == false) {
            int t = 1;
            dfs(-1, i, adj, c, d, t, ans);  
        }
    }
    return ans;
}