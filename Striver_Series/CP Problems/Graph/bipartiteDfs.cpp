bool dfs(int parColor, int node, vector<vector<int>>& adj, vector<int>& color) {
    if(parColor == 1) color[node] = 0;
    else color[node] = 1;
    for(auto child : adj[node]) {
        if(color[child] == color[node]) return false;
        if(color[child] == -1) if(!dfs(color[node], child, adj, color)) return false;
    }
    return true;
}
bool isBipartite(int V, vector<vector<int>>adj){
    vector<int> color(V, -1);
    for(int i=0; i<V; i++) {
        if(color[i] == -1) {
            if(!dfs(0, i, adj, color)) return false;
        }
    }
    return true;
}

int main() {
	vector<vector<int>> adj = {{}};   // adjency list graph.
	cout<<isBipartite(5, adj);
}