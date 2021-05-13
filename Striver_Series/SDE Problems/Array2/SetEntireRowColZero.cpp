#include<bits/stdc++.h>
using namespace std;

// errichto videos

 void setZeroes(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    bool first_row_have_zero = false;
    for(int i=0; i<c; i++) {
        if(matrix[0][i] == 0) first_row_have_zero = true;
    }
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(matrix[i][j] == 0) matrix[0][j] = 0;
        }
    }
    
    for(int i=1; i<r; i++){
        bool row_have_zero = false;
        for(int j=0; j<c; j++) {
            if(matrix[i][j] == 0) row_have_zero = true;
            if(matrix[0][j] == 0) matrix[i][j] = 0;
        }
        if(row_have_zero) {
            for(int j=0; j<c; j++) matrix[i][j] = 0;
        }  
    }
    if(first_row_have_zero) for(int i=0; i<c; i++) matrix[0][i] = 0;
}