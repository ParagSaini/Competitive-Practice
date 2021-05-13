#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000;
class obj{
    public:
    int row, col, val;
    obj(int r, int c, int v) {
        row = r; col = c; val = v;
    }
};

class comp{
  public:
  bool operator() (obj a, obj b) {
      return a.val > b.val;
  }
};

// time complexity O(klog(n)), s.c O(n)
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<obj, vector<obj>, comp> minHeap;
    for(int i=0; i<n; i++) {
        minHeap.push(obj(0, i, mat[0][i]));
    }
    
    for(int i=1; i<k; i++) {
        int r = minHeap.top().row;
        int c = minHeap.top().col;
        minHeap.pop();
        
        if((r+1) < n)
            minHeap.push(obj(r+1, c, mat[r+1][c]));
    }
    return (minHeap.top().val);
}

int main() {
    int n = 1000;
    int mat[1000][1000];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            mat[i][j] = i + j;
        }
    }
    cout<<kthSmallest(mat, n, n)<<endl;
    return 0;
}