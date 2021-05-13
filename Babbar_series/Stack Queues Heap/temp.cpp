// #include<unordered_set>
#include<iostream>
#include<algorithm>
// #include<queue>
// #include<climits>
#include<vector>
#include<stack>
using namespace std;
//Time complexity = O(n)
vector<int> LeftNear(int A[], int n) {
    vector<int> result(n, 0);
    stack<int> ch;
    for(int i=0; i<n; i++) {
        if(ch.empty()) {
            ch.push(i);
        }
        else {
            if(A[i] >= A[ch.top()]) {
                ch.push(i);
            }
            else {
                while(!ch.empty() && A[ch.top()] > A[i]) {
                    result[ch.top()] = A[i];
                    ch.pop();
                }
                ch.push(i);
            }
        }
    }
    return result;
}
vector<int> RightNear(int A[], int n) {
   vector<int> result(n, 0);
    stack<int> ch;
    for(int i=n-1; i>=0; i--) {
        if(ch.empty()) {
            ch.push(i);
        }
        else {
            if(A[i] >= A[ch.top()]) {
                ch.push(i);
            }
            else {
                while(!ch.empty() && A[ch.top()] > A[i]) {
                    result[ch.top()] = A[i];
                    ch.pop();
                }
                ch.push(i);
            }
        }
    }
    return result;
}
int findMaxDiff(int A[], int n)
{
  //Your code here
  int max = 0;
  vector<int> Ls = LeftNear(A,n);
  vector<int> Rs = RightNear(A, n);
  for(int i=0; i<Ls.size(); i++) {
      int diff = abs(Ls[i] - Rs[i]);
      if(diff > max) {
          max = diff;
      }
  }
  return max;
}
int main() {
    system("cls");
    int A[] = {2,4,8,7,7,9,3};
    int n = sizeof(A)/sizeof(int);
    cout<<findMaxDiff(A,n);
    return 0;
}