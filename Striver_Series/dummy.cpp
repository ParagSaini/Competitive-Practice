#include <bits/stdc++.h>
using namespace std;
void printPath(vector<int> path) {
	for(int i=0; i<path.size(); i++) cout<<path[i]<<" ";
}
void findPath(vector<vector<char>>& mat, pair<int, int> s, pair<int, int> e, vector<int>& path) {
	if(s == e) {
		if(path.size() == mat.size()*mat.size()-1) {
			printPath(path);
			cout<<(mat.size())<<endl;
			return;
		}
		else return;
	}
	vector<pair<int, int>> dir = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
	mat[s.first][s.second] = '#';
	path.push_back(s.first*mat.size() + s.second + 1);

	for(int i=0; i<dir.size(); i++) {
		int newR = s.first + dir[i].first;
		int newC = s.second + dir[i].second;
		if(newR >= 0 && newR < mat.size() && newC >= 0 && newC < mat.size() && mat[newR][newC] == '.') {
			findPath(mat, {newR, newC}, e, path);
		}
	}
	mat[s.first][s.second] = '.';
	path.pop_back();
}

int countPerfectPair(vector<int> arr) {
	int count = 0;
	for(int i=0; i<arr.size(); i++) {
		for(int j=i+1; j<arr.size(); j++) {
			int s = arr[i] + arr[j];
			double sq = sqrt(s);
			double cb = cbrt(s);
			if( ((sq*sq) == s) || ((cb*cb*cb) == s)){
				cout<<sq<<" "<<cb<<" "<<s<<" ";
				cout<<count<<endl;
				count++;
			}
		}
	}
	return count;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int> arr;
		for(int i=0; i<n; i++) {
			int temp;
			cin>>temp;
			arr.push_back(temp);
		}
		cout<<countPerfectPair(arr)<<endl;
	}
	return 0;
}