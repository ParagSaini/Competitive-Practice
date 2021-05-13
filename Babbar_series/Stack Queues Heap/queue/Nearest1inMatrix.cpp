#include<bits/stdc++.h>
using namespace std;
class RC{
    public:
    int r,c;
    RC(int a, int b) {
        r = a; 
        c = b;
    }
};
// Multisource bfs

void printNear(vector<vector<int>>& mat) {
    queue<RC> q;       // queue for doing bfs
    vector<vector<bool>> visited(mat.size());  //visited nodes
    vector<RC> dir = {RC(1,0), RC(0,1), RC(-1,0), RC(0, -1) };

    // initialising the visited nodes to false, not visited.
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat[i].size(); j++) {
            visited[i].push_back(false);
        }
    }
    // push all 1's in the queue and mark them visited.
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat[i].size(); j++) {
            if(mat[i][j] == 1) {
                q.push(RC(i,j));
                visited[i][j] = true;
            }
        }
    }
    // doing breadth first search
    while(!q.empty()) {
        RC temp = q.front();
        q.pop();
        for(int i=0; i<dir.size(); i++) {
            int newRow = temp.r + dir[i].r;
            int newCol = temp.c + dir[i].c;
            if(newRow < 0 || newRow >= mat.size() || newCol < 0 || newCol >= mat[0].size()) {
                continue;
            }
            if(!visited[newRow][newCol]) {
                mat[newRow][newCol] = mat[temp.r][temp.c] + 1;
                q.push(RC(newRow, newCol));
                visited[newRow][newCol] = true;
            }
        }
    }

    // printing the distance matrix.
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat[i].size(); j++) {
            cout<<(mat[i][j]-1)<<" ";
        }
    }
}
int main()
 {
	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {
	    int r, c;
	    cin>>r>>c;
	    vector<vector<int>> mat(r);
	    for(int i=0; i<r; i++) {
	        for(int j=0; j<c; j++) {
	            int temp;
	            cin>>temp;
	            mat[i].push_back(temp);
	        }
	    }
	    printNear(mat);
	    cout<<endl;
	}
	return 0;
}