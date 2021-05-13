#include<bits/stdc++.h>
using namespace std;

// t.c --- BFS
void FloodFill(int** arr, int n, int m, int x, int y, int k) {
    int orgVal = arr[x][y];
    queue<pair<int, int>> q;
    vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    q.push({x,y});
    arr[x][y] = k;
    
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0; i<dir.size(); i++) {
            int newR = cur.first + dir[i].first;
            int newC = cur.second + dir[i].second;
            if(newR >= 0 && newR < n && newC >=0 && newC < m && arr[newR][newC] == orgVal) {
                q.push({newR, newC});
                arr[newR][newC] = k;
            }
        }
    }
}
int main()
 {
	int t;
	cin>>t;
	while(t--) {
	    int n, m, x, y, k;
	    cin>>n>>m;
	    int** arr = new int*[n];
	    for(int i=0; i<n; i++) {
	        arr[i] = new int[m];
	    }
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            int temp;
	            cin>>temp;
	            arr[i][j] = temp;
	        }
	    }
	    cin>>x>>y>>k;
	    FloodFill(arr, n, m, x, y, k);
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            cout<<arr[i][j]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}