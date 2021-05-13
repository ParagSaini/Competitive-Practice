#include<bits/stdc++.h>
using namespace std;
// optimal Solution 
// Using the Bfs, if cur value is '1' then do bfs and mark all the adjacent using bfs to '0', this is our island and marking it zero helps us to count the other island easily 

void callBfs(vector<vector<char>>& grid, int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    grid[r][c] = '0';
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0; i<dir.size(); i++) {
            int newRow = cur.first + dir[i].first;
            int newCol = cur.second + dir[i].second;
            if(newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size() || grid[newRow][newCol] == '0') continue;
            q.push({newRow, newCol});
            grid[newRow][newCol] = '0';

        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0) return 0;
    if(grid[0].size() == 0) return 0;
    int count = 0;
    
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[0].size(); j++) {
            if(grid[i][j] == '1') {
                count += 1;
                callBfs(grid, i, j);
            }
        }
    }
    return count;
}


// Approach using graph, correct but time consuming and very much code. COUNT THE COMPONENT IN A GRAPH IS THE NUMBER OF ISLANDS

void createGraph(vector<vector<char>>& grid, unordered_map< int, vector<int>>& graph) {
    int row = grid.size();
    int col = grid[0].size();
    
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(grid[i][j] == '0') continue;

            // converting it to linear indexing, so that we don't have to store {row, col} pair
            int linearIndex = i * col + j;
            vector<int>& curAdj = graph[linearIndex];
            for(int k=0; k<dir.size(); k++) {
                int newRow = i + dir[k].first;
                int newCol = j + dir[k].second;
                if(newRow < 0 || newCol < 0 || newRow >= row || newCol >= col || grid[newRow][newCol] == '0') continue;
                // converting it to linear indexing, so that we don't have to store {row, col} pair
                int linearVal = newRow * col + newCol;
                curAdj.push_back(linearVal);
            }
        }
    }
}
void printGraph(unordered_map<int, vector<int>> graph) {
    for(auto k : graph) {
        cout<<k.first<<"->";
        for(int i=0; i<k.second.size(); i++) cout<<k.second[i]<<" ";
        cout<<endl;
    }
}
int countComponent(unordered_map<int, vector<int>>& graph) {
    unordered_set<int> visited;
    int count = 0;
    for(auto k : graph) {
        int vert = k.first;
        if(!visited.count(vert)) {
            visited.insert(vert);
            queue<int> q;
            q.push(vert);
            while(!q.empty()) {
                int curNode = q.front();
                q.pop();
                for(int i=0; i<graph[curNode].size(); i++) {
                    int neighbor = graph[curNode][i];
                    if(!visited.count(neighbor)) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            count++;
        }
    }
    return count;
}
int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0) return 0;
    if(grid[0].size() == 0) return 0;
    unordered_map<int, vector<int>> graph;
    createGraph(grid, graph);
    return countComponent(graph);
}