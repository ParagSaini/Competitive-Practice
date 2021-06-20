#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
class node {
    public:
    pair<int, int> p;
    char dir;
    node(pair<int, int> a, char ch) {
        p = a;
        dir = ch;
    }
};
vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(vector<string>& grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    queue<node> q;
    string seq;
    q.push(node(make_pair(x,y), 'S'));
    grid[x][y] = '#';

    while(!q.empty()) {
        int r = q.front().p.first, c = q.front().p.second;
        char ch = q.front().dir;
        seq.push_back(ch);

        q.pop();

        for(int i=0; i<dir.size(); i++) {
            int nR = r + dir[i][0], nC = c + dir[i][1];
            if(nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == '#') continue;

            char curDir;
            if(dir[i][0] == 1) curDir = 'D';
            else if(dir[i][0] == -1) curDir = 'U';
            else if(dir[i][1] == 1) curDir = 'R';
            else curDir = 'L';

            if(grid[nR][nC] == 'B') {
                // do answer;
                cout<<"YES"<<endl;
                cout<<(seq.length()-1)<<endl;
                for(int i=1; i<seq.length(); i++) cout<<seq[i];
                cout<<curDir<<endl;
                return;
            }
            q.push(node(make_pair(nR, nC), curDir));
            grid[nR][nC] = '#';
        }
        // seq.pop_back();
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
        for(int i=0; i<n; i++) cin>>grid[i];
        bool got = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 'A') {
                    bfs(grid, i, j);
                    got = true;
                    break;
                }
            }
            if(got) break;
        }
    }
    return 0;
}