#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(m+n); ---optimal
bool searchInMat(vector<vector<int>>& matrix, int val) {
    // maintaining the two pointer i and j;
    int row = matrix.size();
    int col = matrix[0].size();
    
    int i = 0;
    int j = col-1;
    
    // i and j should in boundary of the matrix.
    while(i < row && j >= 0) {
        int curEle = matrix[i][j];
        if(val == curEle) return true;
        if(val > curEle) i++;
        else j--;
    }
    return false;
}