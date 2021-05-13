#include<bits/stdc++.h>
using namespace std;

// leetcode- Optimal Solution O(lg(mn));
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0) return false;
    int row = matrix.size();
    int col = matrix[0].size();
    
    int s = 0;
    int e = row*col - 1;
    // think the matrix as a sorted list and do binary search.
    while( s <= e) {
        int mid = (s+e)/2;
        
        int midEleRow = mid/col;  // division operator gives rowNumber
        int midEleCol = mid%col;  // modulos give col number.
        
        int curEle = matrix[midEleRow][midEleCol];
        
        if(target == curEle) return true;
        if(target > curEle) s = mid+1;
        else e = mid - 1;
    }
    return false;
}


// leetcode Solution (mine).  O(lg(mn))
int justSmallerRowIndex(vector<vector<int>>& matrix, int target) {
    int s = 0;
    int e = matrix.size()-1;
    
    while(s <= e) {
        int mid = (s+e)/2;
        int curEle = matrix[mid][0];
        
        if(curEle == target) return mid;
        if(target > curEle) s = mid+1;
        else e = mid-1;
    }
    if(e <= matrix.size() && e >= 0) return e;
    else return -1;  

}
bool searchInRow(int RowIndex, vector<vector<int>>& matrix, int target) {
    int s = 0;
    int e = matrix[0].size()-1;
    
    while(s <= e) {
        int mid = (s+e)/2;
        int curEle = matrix[RowIndex][mid];
        
        if(curEle == target) return true;
        if(target > curEle) s = mid+1;
        else e = mid-1;
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0 || matrix[0].size() == 0) return false;
    
    int rowIndex = justSmallerRowIndex(matrix, target);
    if(rowIndex == -1) return false;
    return searchInRow(rowIndex, matrix, target);
    
}

