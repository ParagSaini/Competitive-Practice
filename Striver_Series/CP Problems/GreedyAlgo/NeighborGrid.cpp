#include<bits/stdc++.h>
using namespace std;

int countMaxNeigbor(int i,int j, int n, int m) {
    if(i == 0 || i == n-1) {
        if(j == 0 || j == m-1) return 2;
        return 3;
    }
    if(j == 0 || j == m-1) return 3;
    return 4;
}

void checkMatrix(int n, int m) {
    bool isPossible = true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int a;
            scanf("%d", &a);
            int maxNeigbor = countMaxNeigbor(i, j, n, m);
            if(a > maxNeigbor) isPossible = false;
        }
    }
    if(!isPossible) {
        printf("NO \n");
        return;
    }
    printf("YES \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("%d ", countMaxNeigbor(i, j, n, m));
        }
        printf("\n");
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        checkMatrix(n,m);
    }
    return 0;
}