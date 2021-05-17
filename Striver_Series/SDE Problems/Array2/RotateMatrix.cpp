#include<bits/stdc++.h>
using namespace std;

// t.c O(n2), s.c O(1)
void rotate(vector<vector<int>>& matrix) {
    // transpose and reverse every row
    int n = matrix.size();
    // transpose
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reversing the row.
    for(int i=0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

}