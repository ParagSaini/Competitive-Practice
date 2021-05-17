#include<bits/stdc++.h>
using namespace std;

// t.c O(n2) s.c O(n2)
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows);
    for(int i=0; i<numRows; i++) {
        result[i].resize(i+1);    // each row contains i+1 elements
        result[i][0] = 1;
        result[i][i] = 1;
        for(int j=1; j<=i-1; j++) {    // from 1st column to second last column
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    return result;
}
int main() {
    int num = 5;
    vector<vector<int>> r = generate(num);
    for(int i=0; i<r.size(); i++ ){
        for(int j=0; j<r[i].size(); j++) {
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}