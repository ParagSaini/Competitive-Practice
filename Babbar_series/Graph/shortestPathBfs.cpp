int ShortestPathLengthBfs(int source, int destination, unordered_map<int, vector<int>> adj) {
    if(source == destination) return 0;
    int length = -1;
    queue<int> q;
    unordered_map<int, int> parentMap;
    unordered_set<int> explored;
    q.push(source);
    parentMap[source] = source;
    explored.insert(source);

    bool flag = false;
    while(!q.empty()) {
        int x = q.front();

        for(int i=0; i<adj[x].size(); i++) {
            int temp = adj[x][i];
            if(temp == destination) {
                parentMap[temp] = x;
                flag = true;
                break;
            }
            else if(!explored.count(temp)) {
                q.push(temp);
                explored.insert(temp);
                parentMap[temp] = x;
            }
        }
        if(flag) break;
        q.pop();
    }
    if(flag == false) return -1;             // there is no root between two vertices

    vector<int> pathVert;
    pathVert.push_back(destination);
    int sr = destination;
    while(sr != source) {
        pathVert.push_back(parentMap[sr]);
        sr = parentMap[sr];
    }
    for(auto i : pathVert) cout<<i<< " ";       // printing the path
    cout<<endl;
    return pathVert.size();
}