class Solution {
public:
    bool bfs(vector<vector<int>>& grid, vector<vector<int>>& grid2, int i, int j) {
        bool ans = true;
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        grid[i][j] = -1;
        if(grid2[i][j] != -1) ans = false;
        
        while(!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            for(int k=0; k<4; k++) {
                int nR = front.first + dir[k].first, nC = front.second + dir[k].second;
                if(nR >= n || nR < 0 || nC >= m || nC < 0 || grid[nR][nC] == 0 || grid[nR][nC] == -1) continue;
                if(grid2[nR][nC] != -1) ans = false;
                grid[nR][nC] = -1;
                q.push(make_pair(nR, nC));
            }
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        int x = grid2.size(), y = grid2[0].size();
        int cnt = 0;
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(grid1[i][j] == 1) {
                    bfs(grid1, grid2, i, j);
                }
            }
        }
      
        for(int i =0; i<x; i++) {
            for(int j =0; j<y; j++) {
                if(grid2[i][j] == 1) {
                    if(bfs(grid2, grid1, i, j)) {
                        // cout<<i<<" "<<j<<endl;
                        cnt++;
                    }
                }
            }
        }
     
        return cnt;
        
        
    }
};