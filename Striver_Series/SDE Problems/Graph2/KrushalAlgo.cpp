#include<bits/stdc++.h>
using namespace std;
class disjointSet{
	public:
	vector<int> ar;
	disjointSet(int n) {
		for(int i=0; i<n; i++) ar.push_back(-1);
	}
	int find(int val) {
		if(ar[val] == -1) return val;
		int Up_parent = find(ar[val]);
		ar[val] = Up_parent;   // path compression
		return Up_parent;
	}
	bool setUnion(int val1, int val2) {
		int leader1 = find(val1);
		int leader2 = find(val2);
		if(leader1 != leader2) ar[leader2] = val1;
		if(leader1 != leader2) return true;
		return false;
	}
	void printSet() {
		for(int i=0; i<ar.size(); i++) cout<<ar[i]<<" ";
	}
};
class graphEdge {
	public:
	int src, dest, weight;
	graphEdge(int s, int d, int w) {
		src = s;
		dest = d;
		weight = w;
	}
};
bool compare(graphEdge a, graphEdge b) {
	return a.weight < b.weight;
}
vector<graphEdge> minSpan(vector<graphEdge>& graph, int v) {
	vector<graphEdge> result;
	disjointSet d_set(v);
	for(int i=0; i<graph.size(); i++) {
		int curW = graph[i].weight;
		int curS = graph[i].src;
		int curD = graph[i].dest;

		if(d_set.setUnion(curS, curD)) {
			result.push_back(graphEdge(curS, curD, curW));
		}
	}
	return result;
}
int main()
{
	vector<graphEdge> graph;
	int v = 9; // 0-8
	graph.push_back(graphEdge(3,5,14));
	graph.push_back(graphEdge(1,7,11));
	graph.push_back(graphEdge(5,4,10));
	graph.push_back(graphEdge(3,4,9));
	graph.push_back(graphEdge(1,2,8));
	graph.push_back(graphEdge(0,7,8));
	graph.push_back(graphEdge(7,8,7));
	graph.push_back(graphEdge(2,3,7));
	graph.push_back(graphEdge(8,6,6));
	graph.push_back(graphEdge(2,5,4));
	graph.push_back(graphEdge(0,1,4));
	graph.push_back(graphEdge(6,5,2));
	graph.push_back(graphEdge(8,2,2));
	graph.push_back(graphEdge(7,6,1));
	sort(graph.begin(), graph.end(), compare);
	// for(int i=0; i<graph.size(); i++) cout<<graph[i].weight<<" ";
	vector<graphEdge> MinSpanTree= minSpan(graph, v);
	for(int i=0; i<MinSpanTree.size(); i++) {
		cout<<"s->"<<MinSpanTree[i].src<<" "<<"d->"<<MinSpanTree[i].dest<<" "<<"w->"<<MinSpanTree[i].weight;
		cout<<endl;
	}
	return 0;
}