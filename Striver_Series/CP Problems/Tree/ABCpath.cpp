#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
vector<vector<int>> dir = {{1,0}, {0, 1}, {-1, 0}, {0, -1}, {1,1}, {1,-1}, {-1, 1}, {-1, -1}};

// DFS and dp together.

int dfs(vector<string>& mat, vector<vector<int>>& visited , int i, int j, char cur, vector<vector<int>>& dp) {

    int m = mat.size(), n = mat[0].size(), maxi = 1;
    if(dp[i][j] != -1) return dp[i][j];

    visited[i][j] = 1;
    for(int k=0; k<dir.size(); k++) {
        int nR = i + dir[k][0], nC = j + dir[k][1];
        if(nR < 0 || nR >= m || nC < 0 || nC >= n || visited[nR][nC])  continue;
        if(mat[nR][nC] == (char)(cur + 1)) {
            int len = 1 + dfs(mat, visited, nR, nC, mat[nR][nC], dp);
            maxi = max(len, maxi);
        }
    }
    visited[i][j] = 0;
    dp[i][j] = maxi;
    return dp[i][j];
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int m, n, k = 1;
    cin>>m>>n;
    while(m != 0) {
        int maxi = 0;
        vector<string> mat(m);
        vector<vector<int>> visited(m), dp(m);
        for(int i=0; i<m; i++) {
            cin>>mat[i];
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                visited[i].push_back(0);
                dp[i].push_back(-1);
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 'A') {
                    int len = dfs(mat, visited, i, j, 'A', dp);
                    maxi = max(len, maxi);
                    if(maxi == (m*n)) break;
                }
            }
        }
        cout<<"Case "<<k<<": "<<maxi<<endl;
        scanf("%d %d", &m, &n);
        k++;
    }
    return 0;
}