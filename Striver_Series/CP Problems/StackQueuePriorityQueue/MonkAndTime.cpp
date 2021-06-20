#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

int solve(queue<int> called, queue<int> ideal) {
    int time = 0;
    int n = called.size();
    for(int i=0; i<n; i++) {
        while(called.front() != ideal.front()) {
            int front = called.front();
            called.pop();
            called.push(front);
            time++;
        }
        called.pop();
        ideal.pop();
        time++;
    }
    return time;
}
int main() {
    int t;
    t = 1;
    while(t--) {
        int n;
        cin>>n;
        queue<int> called, ideal;
        for(int i =0; i<n; i++) {
            int temp;
            cin>>temp;
            called.push(temp);
        }
        for(int i =0; i<n; i++) {
            int temp;
            cin>>temp;
            ideal.push(temp);
        }
        cout<<solve(called, ideal)<<endl;
    }
    return 0;
}