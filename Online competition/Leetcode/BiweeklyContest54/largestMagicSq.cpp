#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

// bool isMagic(vector<vector<int>>& grid, int k, vector<vector<int>> prefixR, vector<vector<int>> prefixC) {
    
// }
bool isMagic(vector<vector<int>>& grid, int i1, int j1, int i2, int j2) {
    ll dia1 = 0, dia2 = 0, rsum = 0, csum =0;
    int k = j1;
    for(int i=i1; i<=i2; i++) {
        for(int j =i1; j<=j2; j++) {
            if(i == j) dia1 += grid[i][j];
            if(j == k) {
                dia2 += grid[i][j];
                k--;
            }
        }
    }
    if(dia1 != dia2) return false;
    for(int i=i1; i<=i2; i++) {
        ll sum = 0, sum2 = 0;
        for(int j =i1; j<=j2; j++) {
            sum += grid[i][j];
            sum2 += grid[j][i];
        }
        if(i != i1 && (rsum != sum || sum2 != csum)) return false;
        rsum = sum; 
        csum = sum2; 
    }
    if(rsum == csum && rsum == dia1) return true;
    return false;
}
bool containsMagic(int k, vector<vector<int>>& grid) {
    return true;
}
int largestMagicSquare(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    // vector<vector<int>> prefixR(n), prefixC(n);
    // for(int i=0; i<n; i++) {
    //     int rsum = 0;
    //     for(int j=0; j<n; j++) {
    //         rsum += grid[i][j];
    //         prefixR[i].push_back(rsum);
    //         if(i == 0) prefixC[i].push_back(grid[i][j]);
    //         else {
    //             prefixC[i].push_back(grid[i][j] + prefixC[i-1][j]);
    //         }
    //     }
    // }

    int mini = 2, maxi = min(n, m), ans = 1;
    // while(mini <= maxi) {
    //     int mid = (mini+maxi)/2;
    //     if(isMagic(grid, mid, prefixR, prefixC)) {
    //         ans = mid;
    //         mid = maxi + 1;
    //     } else {
    //         maxi = mid-1;
    //     }
    // }
    cout<<isMagic(grid, 0, 2, 2, 2)<<endl;
    for(int i=min(n,m); i>=2; i++) {
        if(containsMagic(i, grid)) return i;
    }
    return 1;
}
int main() {
    vector<vector<int>> mat = {{5,1,3,1},{9,3,3,1},{1,3,3,8}};
    cout<<largestMagicSquare(mat);
    return 0;
}