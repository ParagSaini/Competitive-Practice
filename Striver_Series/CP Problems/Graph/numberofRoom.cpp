#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(vector<string>& grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    grid[x][y] = '#';

    while(!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        for(int i=0; i<dir.size(); i++) {
            int nR = r + dir[i][0], nC = c + dir[i][1];
            if(nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == '#') continue;
            q.push(make_pair(nR, nC));
            grid[nR][nC] = '#';
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--) {
        int n, m, cnt = 0;
        cin>>n>>m;
        vector<string> grid(n);
        for(int i=0; i<n; i++) cin>>grid[i];
    
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '.') {
                    bfs(grid, i, j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}