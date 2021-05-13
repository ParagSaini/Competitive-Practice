bool isCyclicDfsUtil(int start,vector<int>& VertStat, vector<int> adj[] ) {
    VertStat[start] = 1;
    for(int i=0; i<adj[start].size(); i++ ) {
        int Vert = adj[start][i];
        if(VertStat[Vert] == 1) {
            return true;
        }
        else {
            bool iscycle =  isCyclicDfsUtil(Vert, VertStat, adj);
            if(iscycle) return true;
        }
    }
    VertStat[start] = -1;
    return false;
}
// vector<int> adj[] contains the Vertex and their adjacent
bool isCyclic(int V, vector<int> adj[])   // V = no. of vertices
// 0 <= u,n <= V-1
{
   vector<int> VertStat(V,0);          // contain the status of the each vertex, 0 means not visited, 1 means in the running stack, -1 means we explored it completely- it can't form a cycle
    for(int i=0; i<V; i++) {          // To check the subgraph in graph
        if(VertStat[i] == 0) {
            bool iscycle = isCyclicDfsUtil(i, VertStat, adj);
            if(iscycle) return true;
        }
    }
   return false;
}