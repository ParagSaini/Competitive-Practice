#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows);
    if(numRows <= 0) return result;
    result[0].push_back(1);
    
    for(int i=1; i<numRows; i++) {
        result[i].push_back(1);
        int s = i;
        // no. of element in ith row is (i+1).
        while(--s) {
            int index = result[i].size();
            
            int a = result[i-1][index];
            int b = result[i-1][index-1];
            
            result[i].push_back(a+b);
        }
        result[i].push_back(1);
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