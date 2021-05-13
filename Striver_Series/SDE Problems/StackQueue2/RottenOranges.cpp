#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    int t = 0;
    queue<pair<int, int>> rottens;
    vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1,0}, {0, -1}};
    
    // intialising the queue
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(grid[i][j] == 2) rottens.push({i,j});
        }
    }
    
    while(!rottens.empty()) {
        int size = rottens.size();
        // going per layer
        while(size--) {
            pair<int, int> coord = rottens.front();
            rottens.pop();
            for(int i=0; i<dir.size(); i++) {
                int newRow = coord.first + dir[i].first;
                int newCol = coord.second + dir[i].second;
                
                if(newRow >= 0 && newCol >= 0 && newRow < row && newCol < col && grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2;
                    rottens.push({newRow, newCol});
                }                
            }
        }
        // this is important, when all are rottens we wouldn't increament the time.
        if(!rottens.empty())
            t++;
    }
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(grid[i][j] == 1) return -1;
        }
    }
    return t;
    
}