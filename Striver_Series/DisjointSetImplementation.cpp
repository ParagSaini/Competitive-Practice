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
	void setUnion(int val1, int val2) {
		int leader1 = find(val1);
		int leader2 = find(val2);
		if(leader1 != leader2) ar[leader2] = leader1;
	}
	void printSet() {
		for(int i=0; i<ar.size(); i++) cout<<ar[i]<<" ";
	}
};
int main()
{
	disjointSet d(10);
	d.setUnion(0,1);
	d.setUnion(1,2);
	d.setUnion(2,3);
	d.setUnion(3,4);
	d.setUnion(4,5);
	d.setUnion(5,6);
	d.setUnion(6,7);
	d.setUnion(7,8);
	d.setUnion(8,9);
	d.printSet();
	return 0;
}