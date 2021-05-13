#include<bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>>& matrix) {
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<i; j++) {
            swap(matrix[i][j] , matrix[j][i]);
        }
    }
}
void reverseCol(vector<vector<int>>& matrix) {
    int s = 0;
    int e = matrix[0].size()-1;
    while(s < e) {
        for(int i=0; i<matrix.size(); i++) {
            swap(matrix[i][s], matrix[i][e]);
        }
        s++;
        e--;
    }
}
void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    reverseCol(matrix);
}