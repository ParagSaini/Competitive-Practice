// link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
#include<unordered_set>
#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<stack>
using namespace std;

// t.c O(n) && s.c O(1)
int celebrity(vector<vector<int> >& M, int n) {
    int pot1 = 0, pot2 = 1;
    for(int i=1; i<=(n-1); i++) {
        if(M[pot1][pot2] == 1) pot1 = pot2;
        else {};
        pot2++;
    }
    
    for(int i=0; i<n; i++) {
        if(i != pot1) {
            if(M[i][pot1] == 0 || M[pot1][i] == 1) return -1;
        }
    }
    return pot1;
}

// t.c O(n) && s.c O(n)
int getId(vector<vector<int>> ar) {
    stack<int> s;
    for(int i=0; i<ar.size(); i++) {
        s.push(i);
    }

    while(s.size() != 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(ar[a][b] == 1) {
            s.push(b);
        }
        else {
            s.push(a);
        }
    }
    int potential = s.top();
    s.pop();

    for(int i=0; i<ar.size(); i++) {
        if(i != potential) {
            if(ar[i][potential] == 0 || ar[potential][i] == 1) {
                return -1;
            }
        }
    }
    return 1;
}
int main() {
    system("cls");
    vector<vector<int>> temp = {{0,1,0},{0,0,0},{0,1,0}};
    cout<<getId(temp);
    return 0;
}