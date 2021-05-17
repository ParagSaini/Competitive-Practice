#include<bits/stdc++.h>
using namespace std;

// t.c O(mn) s.c O(1), optimising the second  approach of s.c O(m+n)
void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size(), col = matrix[0].size();
    bool firstRowHasZero = false;
    for(int i=0; i<col; i++) if(matrix[0][i] == 0) firstRowHasZero = true;
    
    for(int i=1; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    // traversing back is important because, on traversing front we can change the initial column value, which will create problem for further elements.
    for(int i=row-1; i>=1; i--) {
        for(int j=col-1; j>=0; j--) {
            if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
        }
    }
    if(firstRowHasZero) for(int i=0; i<col; i++) matrix[0][i] = 0;
}

// t.c O(mn), s.c O(m+n)
void setZeroes(vector<vector<int>>& matrix){
    int row = matrix.size(), col = matrix[0].size();
    vector<int> arr1(col, 1);
    vector<int> arr2(row,1);

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(matrix[i][j] == 0) {
                arr1[j] = 0;
                arr2[i] = 0;
            }
        }
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(arr1[j] == 0 || arr2[i] == 0) matrix[i][j] = 0;
        }
    }
    }