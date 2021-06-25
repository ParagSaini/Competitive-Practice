#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
class node {
    public:
    char ch;
    bool visited;
    node(char c, bool v) {
        ch = c;
        visited = v;
    }
};

bool helper(vector<vector<node>>& grid, int a1 , int a2, char its) {
    int n = grid.size(), m =grid[0].size();
    queue<pair<int, int>> indices;
    indices.push(make_pair(a1, a2));
    grid[a1][a2].visited = true;
    vector<pair<int, int>> dir = {{1,0}, {0, 1}, {-1, 0}, {0,-1}};

    while(!indices.empty()) {
        p32 front = indices.front();
        int r = front.first, c = front.second;
        indices.pop();

        for(int i =0; i<4; i++) {
            int nR = r+dir[i].first, nC = c + dir[i].second;
            if(nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC].visited ) {
                continue;
            }  
            if(grid[r][c].ch == grid[nR][nC].ch) return false;
            if(grid[r][c].ch == 'R') grid[nR][nC].ch = 'W';
            else grid[nR][nC].ch = 'R';
            indices.push(make_pair(nR, nC));
            grid[nR][nC].visited = true;
        }
    }
    return true;
    
}
bool solve(vector<vector<node>>& grid) {
    int n = grid.size(), m = grid[0].size();
    for(int i=0; i<n; i++) {
        for(int j =0; j<m; j++) {
            if(grid[i][j].ch == 'R' || grid[i][j].ch == 'W') {
                return helper(grid, i, j, grid[i][j].ch);
            }
        }
    }
    grid[0][0].ch = 'R';
    return helper(grid, 0, 0, 'R');
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<vector<node>> grid(n);
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                char ch;
                cin>>ch;
                grid[i].push_back(node(ch, false));
            }
        }
        if(solve(grid)) {
            cout<<"YES"<<endl;
            for(int i =0; i<n; i++) {
                for(int j=0; j<m; j++) cout<<grid[i][j].ch;
                cout<<endl;
            }
        } else cout<<"NO"<<endl;
    }
    return 0;
}