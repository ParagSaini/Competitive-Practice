void cycleDetection(int node, vector<bool>& curSeqVisited, bool& isExist) {

	if(curSeqVisited[node] == true) {
		isExist = true;
		return;
	}
	if(visited[node] == true) return;

	visited[node] = true;
	curSeqVisited[node] = true;

	for(auto child : edges[node]) {
		cycleDetection(child, curSeqVisited, isExist);
	}

	curSeqVisited[node] = false;
}
bool hasCycle() {
	bool isExist = false;
	vector<bool> curSeqVisited(n+1, false);
	for(int i=1; i<=n; i++) {
		if(visited[i] == false) {
			cycleDetection(i, curSeqVisited, isExist);
		}
	}
	return isExist;
	
}