#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

// bfs with parent retracking.
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void printSequence(vector<vector<pair<int, int>>>& parent, int e1, int e2) {
    string seq;
    while(parent[e1][e2].first != -1) {
        int p1 = parent[e1][e2].first, p2 = parent[e1][e2].second;

        if(p1 + 1 == e1) seq.push_back('D');
        else if(p1-1 == e1) seq.push_back('U');
        else if(p2+1 == e2) seq.push_back('R');
        else seq.push_back('L');

        e1 = p1;
        e2 = p2;
    }
    reverse(seq.begin(), seq.end());
    cout<<seq.length()<<endl<<seq<<endl;
}
void bfs(vector<string>& grid, int x, int y, vector<vector<pair<int, int>>>& parent) {
    int n = grid.size(), m = grid[0].size();

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    grid[x][y] = '#';

    while(!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for(auto dir : dirs) {
            int nR = r + dir[0], nC = c + dir[1];
            
            if(nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == '#') continue;

            if(grid[nR][nC] == 'B') {
                cout<<"YES"<<endl;
                parent[nR][nC] = make_pair(r, c);
                printSequence(parent, nR, nC);
                return;
            }
            q.push(make_pair(nR, nC));
            parent[nR][nC] = make_pair(r, c);
            grid[nR][nC] = '#';
        }
    }
    cout<<"NO"<<endl;
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
        int n, m;
        cin>>n>>m;
        vector<string> grid(n);
        vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, make_pair(-2, -2)));

        for(int i=0; i<n; i++) cin>>grid[i];
        bool got = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 'A') {
                    parent[i][j] = make_pair(-1, -1);
                    bfs(grid, i, j, parent);
                    got = true;
                    break;
                }
            }
            if(got) break;
        }
    }
    return 0;
}