#include<bits/stdc++.h>
using namespace std;
class rc {
    public:
    int row;
    int col;
    rc(int r, int c) {
        row = r;
        col = c;
    }
};
int MinTime(vector<vector<int>> mat) {
    int t = 0, possibleInd = 0;
    int r = mat.size();
    int c = mat[0].size();
    queue<rc> q;
    queue<rc> helper;
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat[i].size(); j++) {
            if(mat[i][j] == 1) {
                possibleInd++;
            } else if(mat[i][j] == 2) {
                q.push(rc(i,j));
                possibleInd++;
            }
        }
    }
    int n = q.size();
    while(!q.empty()) {
        rc temp = q.front();
        q.pop();
        if(temp.col < (c-1) && mat[temp.row][temp.col+1] == 1) {
            mat[temp.row][temp.col+1] = 2;
            helper.push(rc(temp.row,temp.col+1));
            n++;
        }
        if(temp.col > 0 && mat[temp.row][temp.col-1] == 1) {
            mat[temp.row][temp.col-1] = 2;
            helper.push(rc(temp.row, temp.col-1));
            n++;
        }
        if(temp.row < (r-1) && mat[temp.row+1][temp.col] == 1) {
            mat[temp.row+1][temp.col] = 2;
            helper.push(rc(temp.row+1, temp.col));
            n++;
        }
        if(temp.row > 0 && mat[temp.row-1][temp.col] == 1) {
            mat[temp.row-1][temp.col] = 2;
            helper.push(rc(temp.row-1,temp.col));
            n++;
        }
        if(q.empty()) {
            if(helper.empty()) break;
            q = helper;
            queue<rc> emptyqueue;
            helper = emptyqueue;
            t++;
        }
    }
    if(n == possibleInd) return t;
    return -1;
}
int main()
 {
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
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
	    cout<<MinTime(mat)<<endl;
	}
	return 0;
}