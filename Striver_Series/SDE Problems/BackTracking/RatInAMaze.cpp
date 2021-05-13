#include<bits/stdc++.h>
using namespace std;
const int MAX = 5;

void printPathHelper(int m[MAX][MAX],pair<int, int> Start, pair<int, int>& destiny, string Path, vector<string>& result) {

    if(Start.first == destiny.first && Start.second == destiny.second) {
        // reached at the destiny.
        result.push_back(Path);
        return;
    }
    vector<pair<int, int>> direction = {{1,0}, {0, -1}, {0,1}, {-1,0}};
    
    // The below line is important to avoid the loop while finding the path in the matrix.
    m[Start.first][Start.second] = 0;

    for(int i = 0; i<direction.size(); i++) {
        pair<int, int> newStart = {Start.first + direction[i].first, Start.second + direction[i].second};
        
        if(newStart.first < 0 || newStart.second < 0 || newStart.first > destiny.first || newStart.second > destiny.second || m[newStart.first][newStart.second] == 0) {
            continue;
        }
        
        if(i == 0) Path.append("D");
        else if(i == 1) Path.append("L");
        else if(i == 2) Path.append("R");
        else Path.append("U");
        printPathHelper(m, newStart, destiny, Path,result);
        Path.pop_back();
    }
    // revert back to its original value.
    m[Start.first][Start.second] = 1;
}
vector<string> printPath(int m[MAX][MAX], int n) {
    // we have to return all the path from start to destiny in vector<string>
    vector<string> result;
    // Base cases
    if(n == 0 || m[0][0] == 0 ||  m[n-1][n-1] == 0) return result;

    pair<int, int> destiny = {n-1, n-1};
    pair<int, int> Start = {0, 0};
    printPathHelper(m, Start, destiny,"", result);
    return result;
}
